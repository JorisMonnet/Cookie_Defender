#include "monster.h"
#include "math.h"

Monster::Monster(char x) : QGraphicsPixmapItem()
{
    switch(x)
    {
        case 'A':
        setPixmap(QPixmap("../icones/rogue.png").scaled(size,size));
            break;
        case 'B':
        setPixmap(QPixmap("../icones/troll.png").scaled(size,size));
        this->reward*=2;
        this->velocity/=2;
        this->dammage*=2;
            break;
    }

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

double Monster::toCookie(QVector<QPointF> path)
{
    return sqrt(pow(path.last().x()-this->x(),2)+pow(path.last().y()-this->y(),2));
}
