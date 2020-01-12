#include "tower.h"
#include "math.h"
#include "projectile.h"
#include <QDebug>

Tower::Tower(QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent)
{
    set(1);
    showedRange= new QGraphicsEllipseItem();
}

void Tower::set(int level)
{
    int x=level-1;
    this->level=level;
    switch(type)
    {
        case 1: cost=100+x*50;
                range=150+x*35;
                speed=2+x;
                damage=10+x*5;
                setPixmap(QPixmap(QString("../icones/tower/classictower/classictower%1.png").arg(level)).scaled(size,size));
                name="Classic Tower";
            break;
        case 2: cost=150+x*50;
                range=120+x*35;
                speed=2+x;
                damage=11+x*5;
                setPixmap(QPixmap(QString("../icones/tower/magetower/magetower%1.png").arg(level)).scaled(size,size));
                name="Mage Tower";
            break;
    }
}

void Tower::shotTower(Monster *target)
{
    switch(type){
        case 1: target->hp-=damage*(1-target->shield/100);
            break;
        case 2: target->hp-=damage;
            break;
    }
}

bool Tower::hasTarget(Monster *target)
{
    //taking the center of the monster..
    double xM = target->x() + target->size/2;
    double yM = target->y() + target->size/2;
    double distance = sqrt(pow((xM-(this->x()+size/2)),2)+ pow((yM-(this->y()+size/2)),2));
    return distance<=range;
}

QLineF Tower::getAimLine(Monster *target)
{
    return QLineF(this->x(), this->y(), target->x(), target->y());
}

void Tower::showRange(QGraphicsScene*scene,bool isFilled)
{
    if(!scene->items().contains(showedRange)){
        showedRange->setRect(pos().rx()-range+size/2, pos().ry()-range+size/2, range*2, range*2);
        showedRange->setPen(QPen(Qt::black,3));
        if(isFilled)
            showedRange->setBrush(QBrush(QColor(0,0,0,128)));
        scene->addItem(showedRange);
        isShowingRange = true;
    }
}

void Tower::hideRange(QGraphicsScene*scene)
{
    scene->removeItem(showedRange);
    isShowingRange = false;
}

bool Tower::isPlaced(QGraphicsScene*scene)
{
    return scene->items().contains(this);
}
