#include "map.h"
#include "monster.h"
#include <QMessageBox>

#include <QDebug>
//bug: when clicking on the map resizer, the monster is paused
//bug: showed place of  tower 1
/**
 * @brief Map::Map
 * @param parent
 *
 * constructor of the map
 */
Map::Map(QGraphicsView *parent) : QGraphicsView(parent)
{
    settingUpScene();
    settingUpPath();
    timer = new QTimer(this);
    timerSpawn= new QTimer(this);
    timerSpawn->start(2000);
    connect(timer,&QTimer::timeout,this,&Map::moveMonster);
    connect(timerSpawn,&QTimer::timeout,this,&Map::spawnMonster);

}
void Map::settingUpPath()
{
    path<<QPointF(0,475)
        <<QPointF(200,475)
        <<QPointF(200,700)
        <<QPointF(70,700)
        <<QPointF(70,850)
        <<QPointF(450,850)
        <<QPointF(450,300)
        <<QPointF(650,300)
        <<QPointF(650,475)
        <<QPointF(950,475);
    for(int i=0;i<path.size()-1;i++)
        scene->addLine(QLineF(path.at(i),path.at(i+1)));
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
    t[2].set(3);
    t[1].set(2);
    pausePlacement = new QGraphicsRectItem(950,0,50,50);
    showedPlace = new QGraphicsRectItem();
    pausePlacement->setPen(QPen(Qt::blue,2));
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(QPixmap("../icones/bg.jpg").scaled(1000,1000));
    QGraphicsPixmapItem *finish = new QGraphicsPixmapItem(QPixmap("../icones/Cookie.png").scaled(100,100));
    QGraphicsPixmapItem *pauseIcon = new QGraphicsPixmapItem(QPixmap("../icones/pause.png").scaled(50,50));
    pauseIcon->setPos(950,0);
    finish->setPos(950,450);

    scene->addItem(background);
    scene->addItem(finish);
    scene->addItem(pauseIcon);

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
    for (int i=0;i<4;i++)
        if(towerPlacement[i].contains(event->pos())&&!scene->items().contains(showedPlace)){
            statement=true;
            showPlace(i);
        }
        else if(!statement&&scene->items().contains(showedPlace))     // to do check problem "epilepsy" on the first turret
            scene->removeItem(showedPlace);                     //problem is more complicated, the showed Place item is add and remove permanantly in towerPlacement
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
                        attackMonster(monster);
                    }
                }
}
void Map:: spawnMonster()
{
    vectMonster.append(new Monster());
    vectMonster.last()->setPos(path.first().toPoint());
    scene->addItem(vectMonster.last());
}
/**
 * @brief Map::attackMonster
 * giving dammages to the heart
 */
void Map::attackMonster(Monster * monster)
{
    health-=monster->dammage;
    mapUpdate();
    monster->setPos(path.first().toPoint());
    monster->pathIndex=0;
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
    timerSpawn->stop();
    timer->stop();
    vectMonster.clear();
    QMessageBox::information(this,"GAME OVER (u noob)","GAME OVER !!!");
    emit gameEnd();
}

void Map::pauseMenu()
{
    timer->stop();
    timerSpawn->stop();
    emit pauseFunction();
}
