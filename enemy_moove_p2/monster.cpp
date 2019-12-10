#include "monster.h"

/**
* Monster
* Monster's class constructor
*
*/
Monster::Monster(QPointF pStart) : QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../icones/rogue.png").scaled(size,size));
    setPos(pStart);
}



