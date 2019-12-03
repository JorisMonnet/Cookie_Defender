#include "monster.h"


/**
* Monster
* Monster's class constructor
*
*/
Monster::Monster(  ) : QGraphicsRectItem()
{

    this->setRect(0,500,20,20);
    this->setBrush(QPixmap("../enemy_moove_p2/rogue.png"));

}



