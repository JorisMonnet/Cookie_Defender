#include "map.h"
#include "monster.h"


/**
* Map
* map's constructor
*
*/
Map::Map(QWidget *parent) : QGraphicsView(parent)
{
    this->setBackgroundBrush(QBrush(Qt::white));

    QGraphicsScene *scene = new QGraphicsScene(this);
    setScene(scene);
    scene->setSceneRect(-1000,-1000,1000,800);

     //on crée un monstre
    Monster *monster1 = new Monster();
    tabMonster[0]=monster1;

    this->points<<QPointF(0,500)
                <<QPointF(950,500);
    
    //on déplace toute les 15 ms
    timer = new QTimer;

    QObject::connect(timer,&QTimer::timeout,this,&Map::move_monster);
    QObject::connect(timer,&QTimer::timeout,this,&Map::tp_monster);

    timer->start(15);
    scene->addItem(monster1);

}

/**
* move_monster
* moving the monster along the defined path.
*
*/
void  Map::move_monster()
{
    for(Monster * monster : tabMonster)
    {
        monster->moveBy(1,0);
    }
}

/**
* tp_monster
* take the monster and get it back to the very start of the path (optionnal)
*/
void Map::tp_monster()
{
    for(Monster *monster : tabMonster)
    {
        if(monster->x()>=950)
            monster->setX(0);
    }
}

/**
* attack
* giving dammages to the heart
*/
void Map::attack_monster()
{

}


