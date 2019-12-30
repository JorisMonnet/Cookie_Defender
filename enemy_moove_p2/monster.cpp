#include "monster.h"

/**
* Monster
* Monster's class constructor
*
*/
Monster::Monster() : QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../icones/rogue.png").scaled(size,size));
}
void Monster::move(QVector<QPointF>path)
{
    for(int i=0;i<=velocity;i++){
        if(pos()==path.last())
            return;
        if(x() < path.at(pathIndex).x())
            setX(x()+1);
        if(x() > path.at(pathIndex).x())
            setX(x()-1);
        if(y() < path.at(pathIndex).y())
            setY(y()+1);
        if(y() > path.at(pathIndex).y())
            setY(y()-1);
        if(pos() == path.at(pathIndex).toPoint())
            pathIndex++;
    }
}
