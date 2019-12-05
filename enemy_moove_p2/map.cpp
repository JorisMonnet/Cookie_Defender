#include "map.h"
#include "monster.h"

#include  <QTimer>
//bug: when clicking on the map resizer, the monster is paused

/**
 * @brief Map::Map
 * @param parent
 *
 * constructor of the map
 */
Map::Map(QWidget *parent) : QGraphicsView(parent)
{
    settingUpScene();
    this->path<<QPointF(0,500)<<QPointF(950,500);

    QTimer * timer = new QTimer(this);
    timer->start(15);

    QObject::connect(timer,&QTimer::timeout,this,&Map::moveMonster);
    QObject::connect(timer,&QTimer::timeout,this,&Map::attackMonster);

    //creating monster
    vectMonster.append(new Monster());
    for(Monster * monster : vectMonster)
        scene->addItem(monster);
}

/**
 * @brief Map::settingUpScene
 * set up the scene and prepare the tower
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

    textHealth = new QGraphicsTextItem(QString("Health: ")+QString::number(health));
    textHealth->setScale(1.5);
    textHealth->setPos(0,0);
    scene->addItem(textHealth);
    textMoney = new QGraphicsTextItem(QString("Money: ")+QString::number(money));
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
    for(int i=0;i<4;i++)
        if(towerPlacement[i].contains(mapToScene(event->pos()))){
            statement=true;
            if(!(towerCreated[i])){
                createTower(i);
            }
            else{
                showRange(i);
            }
        }
    if(!statement)
        scene->removeItem(&showedRange);
}
void Map::mouseMoveEvent(QMouseEvent*event)
{
    bool statement=false;
    for(int i=0;i<4;i++)
        if(towerPlacement[i].contains(mapToScene(event->pos()))){
            statement=true;
            showPlace(i);
        }
    if(!statement)
       scene->removeItem(&showedPlace);
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
    int r = t[i].range,
        x=towerPositions[i].rx(),
        y=towerPositions[i].ry();

    showedRange.setRect(x-(r/2-50),y-(r/2-50),r,r);
    showedRange.setPen(QPen(Qt::black));
    showedRange.setBrush(QBrush(QColor(0,0,0,128)));
    scene->addItem(&showedRange);
}
void Map::showPlace(int i)
{
    showedPlace.setPen(QPen(Qt::blue,2));
    showedPlace.setRect(towerPositions[i].rx(),towerPositions[i].ry(),100,100);
    scene->addItem(&showedPlace);
}
/**
 * @brief Map::moveMonster
 * make the monsters move along a defined path
 */
void Map::moveMonster()
{
    for(Monster * monster : vectMonster)
        if(monster!=nullptr)
            monster->setPos(monster->x()+1,monster->y());
}
/**
 * @brief Map::attackMonster
 * giving dammages to the heart
 */
void Map::attackMonster()
{
    for(Monster *monster : vectMonster)
        if(monster->x()>=this->width()-monster->size){
            health-=monster->dammage;
            monster->setPos(start);
        }
}
