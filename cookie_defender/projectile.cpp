#include "projectile.h"
#include <qmath.h>

Projectile::Projectile(Tower *tsource, QGraphicsScene *sceneSource, Monster *targetSource)
    :target(targetSource),t(tsource),scene(sceneSource)
{
    setPixmap(QPixmap(QString("../icones/projectile%1.png").arg(t->type)).scaled(20,20));
    timer = new QTimer(this);
    timer->start(10);
    connect(timer,&QTimer::timeout,this,&Projectile::move);
    setPos(t->x()+50,t->y()+50);
    scene->addItem(this);
}

void Projectile::move()
{
    if(scene->items().contains(target)){
        QLineF line = QLineF(x(),y(),target->x()+target->size/2,target->y()+target->size/2);
        moveBy(velocity*qCos(qDegreesToRadians(-line.angle())),velocity*qSin(qDegreesToRadians(-line.angle())));
        if(target->collidingItems().contains(this)){
            t->shotTower(target);
            delete this;
        }
    }
    else
        delete this;
}
