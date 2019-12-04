#include "map.h"
#include "monster.h"

#include  <QTimer>


/**
* Map
* map's constructor
*
*/
Map::Map(QWidget *parent) : QGraphicsView(parent)
{
    settingUpScene();

    this->points<<QPointF(0,500)
                <<QPointF(950,500);
    
    //creating a timer to update the movement each 15 seconds.
    QTimer * timer = new QTimer(this);



    QObject::connect(timer,&QTimer::timeout,this,&Map::move_monster);
    QObject::connect(timer,&QTimer::timeout,this,&Map::tp_monster);

    timer->start(15);

    //error source

    //on crée un monstre
    vectMonster.append(new Monster());


    for(Monster * monster : vectMonster)
        scene->addItem(monster);


}

/**
* settingUpScene
* setting up the scene and preparing the tower
*
*/
void Map:: settingUpScene()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(1000,1000);
        scene= new QGraphicsScene(this);
        setScene(scene);
        t[2].set(2);
        QGraphicsRectItem *topMap = new QGraphicsRectItem(0,0,this->width(),450);
        QGraphicsRectItem *bottomMap = new QGraphicsRectItem(0,550,this->width(),450);
        QGraphicsPixmapItem *finish = new QGraphicsPixmapItem();
        QGraphicsPixmapItem *finish2 = new QGraphicsPixmapItem();

        finish->setPos(950,450);
        finish->setPixmap(QPixmap("../enemy_moove_p2/Cookie.png").scaled(50,50));
        finish2->setPos(950,500);
        finish2->setPixmap(QPixmap("../enemy_moove_p2/Cookie.png").scaled(50,50));
        topMap->setBrush(QBrush(Qt::green));
        topMap->setPen(QPen(Qt::green));
        bottomMap->setBrush(QBrush(Qt::green));
        bottomMap->setPen(QPen(Qt::green));
        scene->addItem(topMap);
        scene->addItem(bottomMap);
        scene->addItem(finish);
        scene->addItem(finish2);
        QGraphicsTextItem *textHealth = new QGraphicsTextItem(QString("Health: ")+QString::number(health));
        textHealth->setScale(1.5);
        textHealth->setPos(0,0);
        scene->addItem(textHealth);

        QGraphicsTextItem *textMoney = new QGraphicsTextItem(QString("Money: ")+QString::number(money));
        textMoney->setScale(1.5);
        textMoney->setPos(0,50);
        scene->addItem(textMoney);

        for(int i=0;i<4;i++)
        {
            towerPlacement[i].setRect(towerPositions[i].rx(),towerPositions[i].ry(),100,100);
            towerPlacement[i].setBrush(QBrush(Qt::red));
            towerPlacement[i].setPen(QPen(Qt::red));
            scene->addItem(&towerPlacement[i]);
        }

        for(int i=0;i<this->height();i+=50)
            scene->addLine(0,i,this->width(),i);
        for(int i=0;i<this->width();i+=50)
            scene->addLine(i,0,i,this->height());
}

void Map::mousePressEvent(QMouseEvent *event)
{
    bool statement=false;
    for(int i=0;i<4;i++){
        if(towerPlacement[i].contains(mapToScene(event->pos()))){
            statement=true;
            if(!(towerCreated[i])){
                createTower(i);
            }
            else{
                showRange(i);
            }
        }
    }
    if(!statement){
        scene->removeItem(&showedRange);
    }
}

void Map::createTower(int index)
{
    if (money>=100){
        t[index].setPos(towerPositions[index]);
        scene->addItem(&t[index]);
        money-=100;
        towerCreated[index]=true;
    }
}

void Map::showRange(int i)
{
    showedRange.setRect(towerPositions[i].rx()-(t[i].range/2-50),towerPositions[i].ry()-(t[i].range/2-50),t[i].range,t[i].range);
    showedRange.setPen(QPen(Qt::black,0));
    showedRange.setBrush(QBrush(QColor(0,0,0,128)));
    scene->addItem(&showedRange);
}


/**
* move_monster
* moving the monster along the defined path.
*
*/
void  Map::move_monster()
{
    for(Monster * monster : vectMonster)
    {
        //monster->moveBy(1,0);
        if(monster!=nullptr)
            monster->setX(monster->x()+1);
    }

}

/**
* tp_monster
* take the monster and get it back to the very start of the path (optionnal)
*/
void Map::tp_monster()
{
    for(Monster *monster : vectMonster)
    {
        if(monster->x()>=910)
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


