#include "map.h"
#include "monster.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

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
    settingUpPath();


    timer = new QTimer(this);
    timer->start(15);
    QTimer *timerSpawn= new QTimer(this);
    timerSpawn->start(2000);

    QObject::connect(timer,&QTimer::timeout,this,&Map::moveMonster);
    QObject::connect(timerSpawn,&QTimer::timeout,this,&Map::spawnMonster);

}

void Map::settingUpPath()
{
    this->path<<QPointF(0,475)
              <<QPointF(200,475)
              <<QPointF(200,700)
              <<QPointF(70,700)
              <<QPointF(70,850)
              <<QPointF(450,850)
              <<QPointF(450,300)
              <<QPointF(650,300)
              <<QPointF(650,475)
              <<QPointF(950,475);
}
/**
 * @brief Map::settingUpScene
 * set up the scene and prepare the tower
 */
void Map::settingUpScene()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,1000);
    scene= new QGraphicsScene(this);
    setScene(scene);
    setMouseTracking(true);
    t[2].set(2);
    QGraphicsRectItem *topMap = new QGraphicsRectItem(0,0,this->width(),450);
    QGraphicsRectItem *bottomMap = new QGraphicsRectItem(0,550,this->width(),450);
    QGraphicsPixmapItem *finish = new QGraphicsPixmapItem(QPixmap("../icones/Cookie.png").scaled(50,50));
    QGraphicsPixmapItem *finish2 = new QGraphicsPixmapItem(QPixmap("../icones/Cookie.png").scaled(50,50));
    pause = new QGraphicsPixmapItem(QPixmap("../enemy_moove_p2/pause.png").scaled(50,50));
    pause->setPos(950,0);
    finish->setPos(950,450);
    finish2->setPos(950,500);

    showedPlace = new QGraphicsRectItem();
    showedRange = new QGraphicsEllipseItem();
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
    scene->addItem(textHealth);
    textMoney = scene->addSimpleText(QString("Money: ")+QString::number(money));
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

    /*for(int i=0;i<this->height();i+=50)
        scene->addLine(0,i,this->width(),i);    //permet d'afficher la grille
    for(int i=0;i<this->width();i+=50)
        scene->addLine(i,0,i,this->height());*/
}

void Map::mousePressEvent(QMouseEvent *event)
{
    bool statement=false;
    for(int i=0;i<4;i++)
        if(towerPlacement[i].contains(mapToScene(event->pos()))){
            statement=true;
            !towerCreated[i]?createTower(i):showRange(i);
        }
    if(!statement)
        scene->removeItem(showedRange);
}
void Map::mouseMoveEvent(QMouseEvent*event)
{
    bool statement=false;
    for(int i=0;i<4;i++)
        if(towerPlacement[i].contains(mapToScene(event->pos()))){
            statement=true;
            showPlace(i);
        }
    if(!statement&&showedPlace->isActive())
       scene->removeItem(showedPlace);
    //if(pause->contains(mapToScene(event->pos())))
        //pausemenu();

}
void Map::keyPressEvent(QKeyEvent*event)
{
    if(event->key()==Qt::Key_Escape)
    {
        timer->stop();
        //TO DO pause menu
    }
}
void Map::createTower(int i)
{
    if (money>=t[i].cost){
        t[i].setPos(towerPositions[i]);
        scene->addItem(&t[i]);
        money-=t[i].cost;
        towerCreated[i]=true;
        mapUpdate();
    }
}

void Map::showRange(int i)
{
    int r=t[i].range,
        x=towerPositions[i].rx(),
        y=towerPositions[i].ry();

    showedRange->setRect(x-(r/2-50),y-(r/2-50),r,r);
    showedRange->setBrush(QBrush(QColor(0,0,0,128)));
    scene->addItem(showedRange);
}
void Map::showPlace(int i)
{
    showedPlace->setPen(QPen(Qt::blue,2));
    showedPlace->setRect(towerPositions[i].rx(),towerPositions[i].ry(),100,100);
    scene->addItem(showedPlace);
}
/**
 * @brief Map::moveMonster
 * make the monsters move along a defined path
 */
void Map::moveMonster()
{
    for(Monster * monster : vectMonster)
            for(int i=0;i<=monster->velocity;i++){

                if(monster->x() < path.at(monster->pathIndex).x())
                    monster->setX(monster->x()+1);

                if(monster->x() > path.at(monster->pathIndex).x())
                    monster->setX(monster->x()-1);

                if(monster->y() < path.at(monster->pathIndex).y())
                    monster->setY(monster->y()+1);

                if(monster->y() > path.at(monster->pathIndex).y())
                    monster->setY(monster->y()-1);

                if(monster->pos() == path.at(monster->pathIndex).toPoint())
                    monster->pathIndex++;
                if(monster->pos() == path.last().toPoint()){
                    qDebug()<<"je suis au dernier point"<<endl;
                    this->attackMonster(monster);
                }
            }
}
/**
 * @brief Map::attackMonster
 * giving dammages to the heart
 */
void Map::attackMonster(Monster* monster)
{
    health-=monster->dammage;
    mapUpdate();
    monster->setPos(path.first().toPoint());
    monster->pathIndex=0;
}
//revoir l'ajout a la liste et la mémoire
void Map:: spawnMonster()
{
    //creating 1 monster
    vectMonster.append(new Monster());  // maybe a tab instead of a vector
    for(Monster * monster : vectMonster)
        scene->addItem(monster);
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
    //QMessageBox::information(this,"GAME OVER (u noob)","GAME OVER !!!");
    setScene(nullptr);
    health=1;
}
