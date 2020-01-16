#include "projectile.h"

Projectile::Projectile(Tower *tsource, QGraphicsScene *sceneSource, Monster *targetSource)
    :target(targetSource),t(tsource),scene(sceneSource)
{
    setPixmap(QPixmap(QString(":/icones/projectile/%1.png").arg(t->projIndex)).scaled(30,30));
    QTimer *timer = new QTimer(this);
    timer->start(10);
    connect(timer,&QTimer::timeout,this,&Projectile::move);
    setPos(t->x()+50,t->y()+50);
    scene->addItem(this);
}

void Projectile::move(void)
{
    if(scene->items().contains(target)){
        QLineF line = QLineF(x(),y(),target->x()+target->size/2,target->y()+target->size/2);
        setRotation(-line.angle());
        moveBy(velocity*qCos(qDegreesToRadians(-line.angle())),velocity*qSin(qDegreesToRadians(-line.angle())));
        if(target->collidingItems().contains(this)){
            t->shot(target);
            delete this;
        }
        else if(target->x()<this->x()-t->range*1.5)
            delete this;
    }
    else
        delete this;
}
