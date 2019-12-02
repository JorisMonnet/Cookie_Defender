#include "monster.h"


/**
* Monster
* Monster's class constructor
* @param QGraphicsItem  * : pointer null to Monster's parent.
*/
Monster::Monster( ) : QGraphicsPixmapItem()
{
    this->setPixmap(QPixmap("rogue.png"));
}



