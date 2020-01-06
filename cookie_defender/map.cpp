#include "map.h"
#include "monster.h"
#include <QMessageBox>

#include <QDebug>

/**
 * @brief Map::Map
 * @param parent
 *
 * constructor of the map
 */
Map::Map(QGraphicsView *parent,QVector<QPointF> pathSource,int towerNumberSource,QPoint towerPositionsSource[],
         int moneySource,QGraphicsPixmapItem *backgroundSource,int widthSource,int heightSource)
    : QGraphicsView(parent)
{
    width = widthSource;
    height = heightSource;
    path = pathSource;
    money = moneySource;
    background = backgroundSource;
    towerNumber = towerNumberSource;
    towerPositions = towerPositionsSource;
    towerPlacement = new QGraphicsRectItem[towerNumber];
    t = new Tower[towerNumber];

    timer = new QTimer(this);
    timerSpawn= new QTimer(this);
    timerTower = new QTimer(this);
    timerWave = new QTimer(this);
    connect(timerTower,&QTimer::timeout,this,&Map::towerDetect);
    connect(timer,&QTimer::timeout,this,&Map::aliveMonster);
    connect(timerWave,&QTimer::timeout,this,&Map::waveMonster);
    connect(timer,&QTimer::timeout,this,&Map::moveMonster);
    connect(timerSpawn,&QTimer::timeout,this,&Map::spawnMonster);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMouseTracking(true);

    scene= new QGraphicsScene(this);
    setScene(scene);
    setSceneRect(0,0,width,height);
    clickableItem = new QGraphicsRectItem();
    clickableItem->setPen(QPen(Qt::blue,2));
    showedPlace = new QGraphicsRectItem();
    showedPlace->setPen(QPen(Qt::blue,2));
    upgrade = new QGraphicsPixmapItem(QPixmap("../icones/upgrade.png").scaled(iconSize,iconSize));
    sell = new QGraphicsPixmapItem(QPixmap("../icones/sell.png").scaled(iconSize,iconSize));
    classicTowerImage = new QGraphicsPixmapItem(QPixmap("../icones/classictower1.png").scaled(iconSize,iconSize));
    mageTowerImage = new QGraphicsPixmapItem(QPixmap("../icones/magetower1.png").scaled(iconSize,iconSize));
    QGraphicsPixmapItem *finish = new QGraphicsPixmapItem(QPixmap("../icones/Cookie.png").scaled(100,100));
    pauseIcon = new QGraphicsPixmapItem(QPixmap("../icones/pause.png").scaled(iconSize,iconSize));
    pauseIcon->setPos(width-iconSize,0);
    finish->setPos(path.last().x(),path.last().y()-iconSize);
    if(background!=nullptr)
        scene->addItem(background);
    scene->addItem(finish);
    scene->addItem(pauseIcon);

    /*progBarCookie = new QProgressBar(this);
    progBarCookie->setOrientation(Qt::Horizontal);
    progBarCookie->setMaximum(health);
    progBarCookie->setMinimum(0);
    QGraphicsProxyWidget *progBarWidget = scene->addWidget(progBarCookie);*/

    textHealth = scene->addSimpleText(QString("Health: ")+QString::number(health));
    textHealth->setScale(1.5);
    textHealth->setPos(0,0);
    textMoney = scene->addSimpleText(QString("Money: ")+QString::number(money));
    textMoney->setScale(1.5);
    textMoney->setPos(0,50);

    for(int i=0;i<towerNumber;i++)
    {
        towerPlacement[i].setRect(towerPositions[i].rx(),towerPositions[i].ry(),t[i].towerSize,t[i].towerSize);
        towerPlacement[i].setBrush(QBrush(Qt::red));
        towerPlacement[i].setPen(QPen(Qt::red));
        scene->addItem(&towerPlacement[i]);
    }
    for(int i=0;i<path.size()-1;i++)
        scene->addLine(QLineF(path.at(i),path.at(i+1)));
}

void Map::mousePressEvent(QMouseEvent *event)
{
    if(scene->items().contains(clickableItem))
        scene->removeItem(clickableItem);

    if(scene->items().contains(classicTowerImage)&&QRectF(classicTowerImage->x(),classicTowerImage->y(),iconSize,iconSize).contains(event->pos()))
        createTower(indexTower,1);
    else if(scene->items().contains(mageTowerImage)&&QRectF(mageTowerImage->x(),mageTowerImage->y(),iconSize,iconSize).contains(event->pos()))
        createTower(indexTower,2);
    else if(QRectF(pauseIcon->x(),pauseIcon->y(),iconSize,iconSize).contains(event->pos()))
        pauseMenu();
    else if(scene->items().contains(upgrade)&&QRectF(upgrade->x(),upgrade->y(),iconSize,iconSize).contains(event->pos())&&t[indexTower].cost<=money){
            money-=t[indexTower].cost;
            hideUpgradeSell();
            t[indexTower].set(t[indexTower].level+1);
    }
    else if(scene->items().contains(sell)&&QRectF(sell->x(),sell->y(),iconSize,iconSize).contains(event->pos())){
        money+=t[indexTower].cost/2;
        t[indexTower].set(1);
        hideUpgradeSell();
        scene->removeItem(&t[indexTower]);
        scene->addItem(&towerPlacement[indexTower]);
    }
    else{
        for (int i=0;i<towerNumber;i++)
            if(!towerPlacement[i].contains(event->pos())&&t[i].isShowingRange){
                if(scene->items().contains(upgrade)){
                    scene->removeItem(upgrade);
                    upgrade->setPos(0,0);
                }
                if(scene->items().contains(sell)){
                    scene->removeItem(sell);
                    sell->setPos(0,0);
                }
                else if(scene->items().contains(classicTowerImage)){
                    scene->removeItem(classicTowerImage);
                    classicTowerImage->setPos(0,0);
                    scene->removeItem(mageTowerImage);
                    mageTowerImage->setPos(0,0);
                }
                t[i].hideRange(scene);
            }
        for(int i=0;i<towerNumber;i++)
            if(towerPlacement[i].contains(event->pos())){
                indexTower=i;
                if(t[i].isPlaced(scene)){
                    t[i].showRange(scene,true);
                    if(t[i].level<t[i].maxLevel&&!scene->items().contains(upgrade)){
                        upgrade->setPos(findPos(i));
                        scene->addItem(upgrade);
                    }
                    if(!scene->items().contains(sell)){
                        scene->addItem(sell);
                        sell->setPos(findPos(i));
                    }
                }
                else{
                    t[i].setPos(towerPositions[i]);
                    t[i].showRange(scene,false);
                    if(!scene->items().contains(classicTowerImage)&&!scene->items().contains(mageTowerImage)){
                        classicTowerImage->setPos(findPos(i));
                        mageTowerImage->setPos(findPos(i));
                        scene->addItem(classicTowerImage);
                        scene->addItem(mageTowerImage);
                    }
                }
            }
    }
    QGraphicsView::mousePressEvent(event);
}
void Map::mouseMoveEvent(QMouseEvent*event)
{
    bool statement=true;
    for(int i=0;i<towerNumber;i++)
        if(towerPlacement[i].contains(event->pos())){
            statement=false;
            if(!scene->items().contains(showedPlace))
                showPlace(i);
        }
    if(statement&&scene->items().contains(showedPlace))
        scene->removeItem(showedPlace);

    if(QRectF(pauseIcon->x(),pauseIcon->y(),iconSize,iconSize).contains(event->pos()))
        createClickableItem(pauseIcon->x(),pauseIcon->y(),iconSize,iconSize);
    else if(scene->items().contains(classicTowerImage)&&QRectF(classicTowerImage->x(),classicTowerImage->y(),iconSize,iconSize).contains(event->pos()))
        createClickableItem(classicTowerImage->x(),classicTowerImage->y(),iconSize,iconSize);
    else if(scene->items().contains(mageTowerImage)&&QRectF(mageTowerImage->x(),mageTowerImage->y(),iconSize,iconSize).contains(event->pos()))
        createClickableItem(mageTowerImage->x(),mageTowerImage->y(),iconSize,iconSize);
    else if(scene->items().contains(upgrade)&&QRectF(upgrade->x(),upgrade->y(),iconSize,iconSize).contains(event->pos()))
        createClickableItem(upgrade->x(),upgrade->y(),iconSize,iconSize);
    else if(scene->items().contains(sell)&&QRectF(sell->x(),sell->y(),iconSize,iconSize).contains(event->pos()))
        createClickableItem(sell->x(),sell->y(),iconSize,iconSize);
    else if(scene->items().contains(clickableItem))
        scene->removeItem(clickableItem);
    QGraphicsView::mouseMoveEvent(event);
}
void Map::keyPressEvent(QKeyEvent*event)
{
    if(event->key()==Qt::Key_Escape)
        pauseMenu();
    QGraphicsView::keyPressEvent(event);
}
void Map::createTower(int i,int type)
{
    t[i].type=type;
    t[i].set(1);
    if (money>=t[i].cost){
        t[i].setPos(towerPositions[i]);
        scene->removeItem(&towerPlacement[i]);
        scene->addItem(&t[i]);
        money-=t[i].cost;
        t[i].hideRange(scene);
        scene->removeItem(classicTowerImage);
        classicTowerImage->setPos(0,0);
        scene->removeItem(mageTowerImage);
        mageTowerImage->setPos(0,0);
        mapUpdate();
    }
}
//detect to decide if a tower have to shot
void Map::towerDetect()
{
    for(int i=0;i<towerNumber;i++)
        if(t[i].isPlaced(scene)){
            int monsterToKill=0;
            for(Monster *monster : vectMonster)
                if(t[i].hasTarget(monster)&&monster->toCookie(path)<vectMonster.at(monsterToKill)->toCookie(path))
                    monsterToKill=vectMonster.indexOf(monster);
            if(monsterToKill!=0)
                t[i].shotTower(vectMonster.at(monsterToKill));
        }
}

void Map::aliveMonster()
{
    for(Monster * monster : vectMonster)
        if(monster->hp<=0){
            money+=monster->reward;
            vectMonster.remove(vectMonster.indexOf(monster));
            delete monster;
        }
}

void Map::createClickableItem(double x,double y,int width,int height)
{
    clickableItem->setRect(x,y,width,height);
    if(!scene->items().contains(clickableItem))
        scene->addItem(clickableItem);
}

void Map::showPlace(int i)
{
    showedPlace->setRect(towerPositions[i].rx(),towerPositions[i].ry(),t[i].towerSize,t[i].towerSize);
    scene->addItem(showedPlace);
}
/**
 * @brief Map::moveMonster
 * make the monsters move along a defined path
 */
void Map::moveMonster()
{
    for(Monster * monster : vectMonster){
        monster->move(path);
        if(monster->pos() == path.last().toPoint())
            attackMonster(monster);
    }
}

void Map::spawnMonster()
{
    vectMonster.append(new Monster());
    vectMonster.last()->setPos(path.first().toPoint());
    scene->addItem(vectMonster.last());
}

void Map::waveMonster()
{
    int k=timerSpawn->interval();
    timerSpawn->setInterval(k-(k/2));
}
/**
 * @brief Map::attackMonster
 * giving dammages to the heart
 */
void Map::attackMonster(Monster * monster)
{
    health-=monster->dammage;
    monster->setPos(path.first().toPoint());
    monster->pathIndex=0;
    mapUpdate();
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
    timerWave->stop();
    timerTower->stop();
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

void Map::hideUpgradeSell()
{
    scene->removeItem(sell);
    sell->setPos(0,0);
    scene->removeItem(upgrade);
    upgrade->setPos(0,0);
    t[indexTower].hideRange(scene);
    mapUpdate();
}

QPointF Map::findPos(int i)
{
    QPointF top = {t[i].x()+iconSize/2,t[i].y()-t[i].range+iconSize/2};
    QPointF down = {t[i].x()+iconSize/2,t[i].y()+t[i].range+iconSize/2};
    QPointF right = {t[i].x()+t[i].range+iconSize/2,t[i].y()+iconSize/2};
    QPointF left = {t[i].x()-t[i].range+iconSize/2,t[i].y()+iconSize/2};
    if(top.y()>0&&isEmpty(top))
        return top;
    if(down.y()<width-iconSize&&isEmpty(down))
        return down;
    if(right.x()<width-iconSize&&isEmpty(right))
        return right;
    if(left.x()>0&&isEmpty(left))
        return left;
    else
        return {0,0};  //TOFIX
}

bool Map::isEmpty(QPointF point)
{
    return !(classicTowerImage->pos()==point||mageTowerImage->pos()==point||upgrade->pos()==point||sell->pos()==point);
}
