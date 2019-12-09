#include "tower.h"
#include "math.h"

Tower::Tower(QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent)
{
    set(1);
}
void Tower::set(int level)
{
    int x=static_cast<int>(log(level*level)+1);
    cost=100*x;
    range=200*x;
    speed=2*x;
    damage=10*x;
    this->level=level;
    setPixmap(QPixmap("./tower.png").scaled(100,100));
}
/*void Tower::attack(Monster *monster)
{

}*/
