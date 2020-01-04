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
    cost=100+x*50;
    range=100+x*25;
    speed=2+x;
    damage=10+x*5;
    this->level=level;
    setPixmap(QPixmap(QString("../icones/tower%1.png").arg(level)).scaled(towerSize,towerSize));
}

void Tower::shotTower(Monster *target)
{
    target->hp-=damage;
}

bool Tower::hasTarget(Monster *target)
{
    //taking the center of the monster..
    double xM=target->x() + target->size/2;
    double yM=target->y() + target->size/2;
    double distance = sqrt(pow((xM-(this->x()+towerSize/2)),2)+pow((yM-(this->y()+towerSize/2)),2));
    return distance<=range;
}
void Tower::showRange(QGraphicsScene*scene,bool isFilled)
{
    if(!scene->items().contains(showedRange)){
        showedRange->setRect(pos().rx()-range+towerSize/2,pos().ry()-range+towerSize/2,range*2,range*2);
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
