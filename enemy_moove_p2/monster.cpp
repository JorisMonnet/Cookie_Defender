#include "monster.h"


/**
* Monster
* Monster's class constructor
*
*/
Monster::Monster(  ) : QObject(),QGraphicsRectItem()
{

    this->setRect(0,480,40,40);
    this->setBrush(QPixmap("../enemy_moove_p2/rogue.png").scaled(40,40));

}



