#include "map.h"
#include "monster.h"
#include <QMessageBox>
//bug: when clicking on the map resizer, the monster is paused

/**
 * @brief Map::Map
 * @param parent
 *
 * constructor of the map
 */
Map::Map(QGraphicsView *parent) : QGraphicsView(parent)
{
    //setBackgroundBrush(QBrush(QPixmap("")));
    settingUpScene();
    //this->path<<QPointF(0,500)<<QPointF(950,500);   // useless currently
    timer = new QTimer(this);
    timer->start(15);
    connect(timer,&QTimer::timeout,this,&Map::moveMonster);
    connect(timer,&QTimer::timeout,this,&Map::attackMonster);
    //creating 1 monster
    Monster *monster1 = new Monster;
    monster1->setPos(start);
    vectMonster.append(monster1);  // maybe a tab instead of a vector
    for(Monster * monster : vectMonster)
        scene->addItem(monster);
}

/**
 * @brief Map::settingUpScene
 * set up the scene and prepare the tower
 */
void Map::settingUpScene()
{
    scene= new QGraphicsScene(this);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMouseTracking(true);
    t[2].set(2);
    QGraphicsRectItem *topMap = new QGraphicsRectItem(0,0,1000,450);
    QGraphicsRectItem *bottomMap = new QGraphicsRectItem(0,550,1000,450);
    pausePlacement = new QGraphicsRectItem(950,0,50,50);
    pausePlacement->setPen(QPen(Qt::blue,2));
    QGraphicsPixmapItem *finish = new QGraphicsPixmapItem(QPixmap("../enemy_moove_p2/Cookie.png").scaled(50,50));
    QGraphicsPixmapItem *finish2 = new QGraphicsPixmapItem(QPixmap("../enemy_moove_p2/Cookie.png").scaled(50,50));
    pause = new QGraphicsPixmapItem(QPixmap("../enemy_moove_p2/pause.png").scaled(50,50));
    pause->setPos(950,0);
    finish->setPos(950,450);
    finish2->setPos(950,500);

    showedPlace = new QGraphicsRectItem();
    topMap->setBrush(QBrush(Qt::green));
    bottomMap->setBrush(QBrush(Qt::green));

    scene->addItem(topMap);
    scene->addItem(bottomMap);
    scene->addItem(finish);
    scene->addItem(finish2);
    scene->addItem(pause);

    textHealth = scene->addSimpleText(QString("Health: ")+QString::number(health));
    textHealth->setScale(1.5);
    textHealth->setPos(0,0);
    textMoney = scene->addSimpleText(QString("Money: ")+QString::number(money));
    textMoney->setScale(1.5);
    textMoney->setPos(0,50);

    for(int i=0;i<4;i++)
    {
        towerPlacement[i].setRect(towerPositions[i].rx(),towerPositions[i].ry(),t[i].towerSize,t[i].towerSize);
        towerPlacement[i].setBrush(QBrush(Qt::red));
        towerPlacement[i].setPen(QPen(Qt::red));
        scene->addItem(&towerPlacement[i]);
    }

    /*for(int i=0;i<this->height();i+=50)
        scene->addLine(0,i,this->width(),i);    //permet d'afficher la grille
    for(int i=0;i<this->width();i+=)
        scene->addLine(i,0,i,this->height());*/
}

void Map::mousePressEvent(QMouseEvent *event)
{
    for(int i=0;i<4;i++)
        if(towerPlacement[i].contains(event->pos()))
            !t[i].isPlaced(scene)?createTower(i):t[i].showRange(scene);
        else if(t[i].isShowingRange)
            t[i].hideRange(scene);
    if(pausePlacement->contains(event->pos()))
        pauseMenu();
}
void Map::mouseMoveEvent(QMouseEvent*event)
{
    bool statement=false;
    for(int i=0;i<4;i++){
        if(towerPlacement[i].contains(event->pos())&&!scene->items().contains(showedPlace)){
            statement=true;
            showPlace(i);
        }
        if(!towerPlacement[i].contains(event->pos())&&!statement&&scene->items().contains(showedPlace))       // to do check problem "eplepsy" on th first turret
            scene->removeItem(showedPlace);
    }
    if(pausePlacement->contains(event->pos())&&!scene->items().contains(pausePlacement))
        scene->addItem(pausePlacement);
    else if(!pausePlacement->contains(event->pos())&&scene->items().contains(pausePlacement))
        scene->removeItem(pausePlacement);
}
void Map::keyPressEvent(QKeyEvent*event)
{
    if(event->key()==Qt::Key_Escape)
        pauseMenu();
}
void Map::createTower(int i)
{
    if (money>=t[i].cost){
        t[i].setPos(towerPositions[i]);
        scene->addItem(&t[i]);
        money-=t[i].cost;
        mapUpdate();
    }
}

void Map::showPlace(int i)
{
    showedPlace->setPen(QPen(Qt::blue,2));
    showedPlace->setRect(towerPositions[i].rx(),towerPositions[i].ry(),t[i].towerSize,t[i].towerSize);
    scene->addItem(showedPlace);
}
/**
 * @brief Map::moveMonster
 * make the monsters move along a defined path
 */
void Map::moveMonster()
{
    for(Monster * monster : vectMonster)
            monster->setPos(monster->x()+monster->velocity,monster->y());
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
            mapUpdate();
            monster->setPos(start);
        }
}

void Map::mapUpdate()
{
    textMoney->setText(QString("Money: ")+QString::number(money));
    textHealth->setText(QString("Health: ")+QString::number(health));
    if(health<=0)
        gameOver();
}

void Map::gameOver()
{
    QMessageBox::information(this,"GAME OVER (u noob)","GAME OVER !!!");
    setScene(nullptr);
    health++;
    emit gameEnd();
}

void Map::pauseMenu()
{
    timer->stop();
    emit pauseFunction();
}
