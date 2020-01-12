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
enum listIcon{
    classicTowerImage,mageTowerImage,pauseIcon,upgrade,sell
};

Map::Map(QGraphicsView *parent,QVector<QPointF> pathSource,int towerNumberSource,QPoint towerPositionsSource[],
         int moneySource,QGraphicsPixmapItem *backgroundSource,int widthSource,int heightSource,int difficultySource)
    : QGraphicsView(parent)
{
    stackHealth=health;
    difficulty=difficultySource;
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
    timerTower = new QTimer(this);
    timerWave = new QTimer(this);
    timerSpawn=new QTimer(this);

    connect(timerTower,&QTimer::timeout,this,&Map::towerDetect);
    connect(timer,&QTimer::timeout,this,&Map::aliveMonster);
    connect(timerWave,&QTimer::timeout,this,&Map::waveMonster);
    connect(timer,&QTimer::timeout,this,&Map::moveMonster);
    connect(timerSpawn,&QTimer::timeout,this,&Map::spawnMonster);
    connect(timer,&QTimer:: timeout,this,&Map::gameWin);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMouseTracking(true);

    scene= new QGraphicsScene(this);
    setScene(scene);
    setSceneRect(0,0,width,height);
    clickableItem = new QGraphicsRectItem();
    clickableItem->setPen(QPen(Qt::blue,2));

    listIcon[0]= upgrade = new QGraphicsPixmapItem(QPixmap("../icones/upgrade.png").scaled(iconSize,iconSize));
    listIcon[1]= sell = new QGraphicsPixmapItem(QPixmap("../icones/sell.png").scaled(iconSize,iconSize));
    listIcon[2]= classicTowerImage= new QGraphicsPixmapItem(QPixmap("../icones/tower/classicTower/classictower1.png").scaled(iconSize,iconSize));
    listIcon[3]= mageTowerImage = new QGraphicsPixmapItem(QPixmap("../icones/tower/mageTower/magetower1.png").scaled(iconSize,iconSize));
    listIcon[4]= pauseIcon = new QGraphicsPixmapItem(QPixmap("../icones/pause.png").scaled(iconSize,iconSize));
    pauseIcon->setPos(width-iconSize,0);

    QGraphicsPixmapItem *finish = new QGraphicsPixmapItem(QPixmap("../icones/Cookie.png").scaled(100,100));
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
        towerPlacement[i].setRect(towerPositions[i].rx(),towerPositions[i].ry(),t[i].size,t[i].size);
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
            createClickableItem(towerPositions[i].x(),towerPositions[i].y(),t[i].size);
        }
    for(int i=0;i<iconNumber;i++)
        if(QRectF(listIcon[i]->x(),listIcon[i]->y(),iconSize,iconSize).contains(event->pos())){
            statement = false;
            createClickableItem(listIcon[i]->x(),listIcon[i]->y(),iconSize);
            }
    if(statement)
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

void Map::towerDetect()
{
    if(!vectMonster.isEmpty())
        for(int i=0;i<towerNumber;i++)
            if(t[i].isPlaced(scene)){
                int monsterToKill=0;
                for(Monster *monster : vectMonster)
                    if(t[i].hasTarget(monster)&&monster->toCookie(path)<vectMonster.at(monsterToKill)->toCookie(path))
                        monsterToKill=vectMonster.indexOf(monster);

                if(t[i].hasTarget(vectMonster.at(monsterToKill)))
                    Projectile *ammo = new Projectile(&t[i],scene,vectMonster.at(monsterToKill));
        }
}

void Map::aliveMonster()
{
    if(!vectMonster.isEmpty())
        for(Monster *monster : vectMonster)
            if(monster->hp<=0){
                money+=monster->reward;
                vectMonster.removeAll(monster);
                delete monster;
                mapUpdate();
            }
}

void Map::createClickableItem(double x,double y,int size)
{
    clickableItem->setRect(x,y,size,size);
    if(!scene->items().contains(clickableItem))
        scene->addItem(clickableItem);
}

void Map::moveMonster()
{
    if(!vectMonster.isEmpty())
        for(Monster * monster : vectMonster){
            monster->move(path);
            if(monster->pos() == path.last().toPoint()){
                health-=monster->damage;
                mapUpdate();
            }
        }
}

void Map::addMonster(char x)
{
    vectMonster.append(new Monster(x));
    vectMonster.last()->setPos(path.first().toPoint());
    scene->addItem(vectMonster.last());

}

int waveCodeTest(int i,QString waveCode,char x)
{
    QString string;
    if(waveCode.at(i)==x){
        for(int j=i+1;j<waveCode.size() && waveCode.at(j)!='A' && waveCode.at(j)!='B';j++){
            if(waveCode.at(j).isDigit())
                string.append(waveCode.at(j));
        }
        return string.toInt();
    }
    return 0;
}

void Map::spawnMonster()
{
    if(difficulty==0){
        if(infiniteSpawn%2==1)
            addMonster('A');
        else if(infiniteSpawn%3==2)
            addMonster('B');
        infiniteSpawn++;
    }
    else{
        if(numberA<=spawnCountA && numberB<=spawnCountB){
            timerSpawn->stop();
            spawnCountA=0;
            spawnCountB=0;
            numberA=0;
            numberB=0;
        }
        else{
            if(statement && spawnCountA++<numberA)
                addMonster('A');
            else if(!statement && spawnCountB++<numberB)
                addMonster('B');
            timerSpawn->setInterval(500);
        }
        statement=!statement;
    }
}
//called each waveTimer => timeout()
//use to get the right waveCode to the current waveIndex
void Map::waveMonster()
{
    if(difficulty==0){
        timerSpawn->start(countTimeInf);
        countTimeInf=countTimeInf-countTimeInf/50;
    }
    else{
        QFile file(QString("../wave/wave%1.txt").arg(difficulty));
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream flow(&file);
            for(int i=0;i<this->waveIndex;i++)
            {
                waveCode=flow.readLine();
            }
            file.close();
            QString string;
            for(int i=0;i<waveCode.size();i++){
                 numberA+=waveCodeTest(i,waveCode,'A');
                 numberB+=waveCodeTest(i,waveCode,'B');
            }
            timerSpawn->start(500);
            waveIndex++;
        }
        else{
            //Catching error
            qDebug()<<"Can't find file"<<endl;
            emit gameWin();
        }
        if(waveCode=="" || waveCode=="\n")
            hasWave=true;
        waveCode.clear();
    }
    timerWave->setInterval(15000);
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
    timer->stop();
    timerWave->stop();
    timerTower->stop();
    vectMonster.clear();
    if(difficulty==0)
        QMessageBox::information(this,"GAME OVER",(QString("GAME OVER !! \nYou lose against a sum\nof %1 ennemy").arg(infiniteSpawn-1)));
    else
        QMessageBox::information(this,"GAME OVER","GAME OVER !!");
    emit gameEnd();
}
void Map::gameWin()
{
    if(vectMonster.isEmpty()&& hasWave){
        QString string;
        timer->stop();
        timerWave->stop();
        timerTower->stop();
        vectMonster.clear();
        for(int i=0;i<3;i++)
            if(health>i*stackHealth/3)
                string.append(">|< ");
        QMessageBox::information(this,"Congratulations","You win the Cookie's War\nSevenans Thanks You for your Epic battle !"
                                                "\ngame star: "+string);
        emit gameEnd();
    }
}

void Map::pauseMenu()
{
    timer->stop();
    remaingTimeWave=timerWave->remainingTime();
    timerWave->stop();
    remaingTimeSpawn=timerSpawn->remainingTime();
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
    for(int i=0;i<iconNumber;i++)
       if(listIcon[i]->pos()==point)
           return false;
    return true;
}
