#include "monster.h"


/**
* Monster
* Monster's class constructor
*
*/
Monster::Monster(QGraphicsItem * ) : QGraphicsRectItem()
{

    this->setRect(0,500,20,20);
    this->setBrush(QPixmap("rogue.png"));

}



