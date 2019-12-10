#include "tower.h"
#include "math.h"

Tower::Tower(QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent)
{
    set(1);
    showedRange= new QGraphicsEllipseItem();
}
void Tower::set(int level)
{
    int x=static_cast<int>(log(level*level)+1);
    cost=100*x;
    range=100*x;
    speed=2*x;
    damage=10*x;
    this->level=level;
    setPixmap(QPixmap("../enemy_moove_p2/tower.png").scaled(towerSize,towerSize));
}
/*void Tower::attack(Monster *monster)
{

}*/
void Tower::showRange(QGraphicsScene*scene)
{
    showedRange->setRect(pos().rx()-range+towerSize/2,pos().ry()-range+towerSize/2,range*2,range*2);
    showedRange->setBrush(QBrush(QColor(0,0,0,128)));
    scene->addItem(showedRange);
    isShowingRange = true;
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
