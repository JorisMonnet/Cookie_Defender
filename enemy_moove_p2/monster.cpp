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



