#include "widget.h"
#include "physicstools.h"

#include <QTimer>
#include <QVector2D>
#include <QGraphicsScene>

const int TOURRET_SHOT = 1;
const double MASS = 10.5;
const double LIFE = 3;

Widget::Widget(QGraphicsView *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    this->setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSceneRect(-width()/2,-height()/2,width(),height());
    setRenderHint(QPainter::Antialiasing, false);
    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode( QGraphicsView::SmartViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode( QGraphicsView::FullViewportUpdate);

    timer = new QTimer(this);
    timer->setInterval(0);

    emmiter.init(TOURRET_SHOT, [&](Particle<QVector2D> & particle, int i){
        ellipses.push_back(scene->addEllipse(particle.position.x(), particle.position.y(), MASS, MASS));
        particle.velocity = QVector2D(0,5.6);
        particle.mass = MASS;
        particle.life = 0;
    });

    time.start();

    connect(timer, &QTimer::timeout, [&] () {
        double dt = 15/1000;
        auto move = QVector2D(0.0, 4.2);
        emmiter.visit([&] (Particle<QVector2D> &particle, int i){
            if(particle.life>LIFE){
                particle.position = {};
                particle.velocity = QVector2D(0, 5.6);
                particle.acceleration = {};
                particle.life = 0;
                particle.mass=5;

                ellipses[i]->setRect(particle.position.x(), particle.position.y(), MASS, MASS);
            }
            else{
                particle.life += dt;
            }
            applyForce(particle ,move);
            ellipses[i]->setX(particle.position.x());
            ellipses[i]->setY(particle.position.y());
        });

        emmiter.update(dt);
        time.restart();
    });
    timer->start();
}


