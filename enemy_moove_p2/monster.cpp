#include "monster.h"

/**
* Monster
* Monster's class constructor
*
*/
Monster::Monster() : QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../enemy_moove_p2/rogue.png").scaled(size,size));
    this->setPos(0,480);
}



