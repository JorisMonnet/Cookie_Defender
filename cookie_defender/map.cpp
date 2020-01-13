#include "map.h"
#include "monster.h"


/**
 * @brief Map::Map
 * @param parent
 *
 * constructor of the map
 */

Map::Map(QGraphicsView *parent,QVector<QPointF> pathSource,int towerNumberSource,QPoint towerPositionsSource[],
         int moneySource,QGraphicsPixmapItem *backgroundSource,int widthSource,int heightSource,int difficultySource)
    : QGraphicsView(parent)
{
    health=stackHealth;
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

    listIcon[0]= new QGraphicsPixmapItem(QPixmap("../icones/pause.png").scaled(iconSize,iconSize));
    listIcon[1]= new QGraphicsPixmapItem(QPixmap("../icones/sell.png").scaled(iconSize,iconSize));
    listIcon[2]= new QGraphicsPixmapItem(QPixmap("../icones/upgrade.png").scaled(iconSize,iconSize));
    listIcon[3]= new QGraphicsPixmapItem(QPixmap("../icones/tower/classictower/classictower1.png").scaled(iconSize,iconSize));
    listIcon[4]= new QGraphicsPixmapItem(QPixmap("../icones/tower/magetower/magetower1.png").scaled(iconSize,iconSize));
    listIcon[0]->setPos(width-iconSize,0);

    QGraphicsPixmapItem *finish = new QGraphicsPixmapItem(QPixmap("../icones/Cookie.png").scaled(100,100));
    finish->setPos(path.last().x(),path.last().y()-iconSize);
    if(background!=nullptr)
        scene->addItem(background);
    scene->addItem(finish);
    scene->addItem(listIcon[0]);
    textHealth = scene->addSimpleText(QString::number(health));
    textHealth->setScale(1.5);
    textHealth->setPos(5+width/5,5);
    textMoney = scene->addSimpleText(QString("Money: ")+QString::number(money));
    textMoney->setScale(1.5);
    textMoney->setPos(0,50);

    for(int i=0;i<towerNumber;i++){
        towerPlacement[i].setRect(towerPositions[i].rx(),towerPositions[i].ry(),t[i].size,t[i].size);
        towerPlacement[i].setBrush(QBrush(Qt::red));
        towerPlacement[i].setPen(QPen(Qt::red));
        scene->addItem(&towerPlacement[i]);
    }
    for(int i=0;i<path.size()-1;i++)
        scene->addLine(QLineF(path.at(i),path.at(i+1)));

    numberOfTowerLvl = howManyFiles("../icones/tower/classictower");
    numberOfMonster= howManyFiles("../icones/monster/pix");
    if(numberOfMonster>0){
        waveTab= new int [numberOfMonster];
        for(int i=0;i<=numberOfMonster-1;i++)
            waveTab[i]=0;
    }

    rectRed=new QGraphicsRectItem(QRect(0,0,width/5,40));
    rectGreen=new QGraphicsRectItem(QRect(0,0,width/5,40));
    rectRed->setBrush(Qt::red);
    rectGreen->setBrush(Qt::green);
    rectGreen->setZValue(1);
    rectRed->setZValue(0);
    scene->addItem(rectGreen);
    scene->addItem(rectRed);

}
int Map::howManyFiles(QString fold)
{
    QDir dir = fold;
    QFileInfoList listFold = dir.entryInfoList(QDir::Dirs | QDir::Files);
    int numberFiles = 0;

        for (int i = 0; i < listFold.size(); ++i) {
            QFileInfo fileInfos = listFold.at(i);
            if(fileInfos.isFile())
                numberFiles++;
        }
     return numberFiles;
}
Map::~Map()
{
   delete [] t;
}
void Map::mousePressEvent(QMouseEvent *event)
{
    if(scene->items().contains(clickableItem))
        scene->removeItem(clickableItem);

    for(int i=3;i<iconNumber;i++)
        if(scene->items().contains(listIcon[i])&&QRectF(listIcon[i]->x(),listIcon[i]->y(),iconSize,iconSize).contains(event->pos()))
            createTower(indexTower,i-2);
    if(QRectF(listIcon[0]->x(),listIcon[0]->y(),iconSize,iconSize).contains(event->pos()))
        pauseMenu();
    else if(scene->items().contains(listIcon[2])&&QRectF(listIcon[2]->x(),listIcon[2]->y(),iconSize,iconSize).contains(event->pos())&&t[indexTower].cost<=money){
            money-=t[indexTower].cost;
            hideUpgradeSell();
            t[indexTower].set(t[indexTower].level+1);
    }
    else if(scene->items().contains(listIcon[1])&&QRectF(listIcon[1]->x(),listIcon[1]->y(),iconSize,iconSize).contains(event->pos())){
        money+=t[indexTower].cost/2;
        t[indexTower].set(1);
        hideUpgradeSell();
        scene->removeItem(&t[indexTower]);
        scene->addItem(&towerPlacement[indexTower]);
    }
    else{
        for (int i=0;i<towerNumber;i++)
            if(!towerPlacement[i].contains(event->pos())&&t[i].isShowingRange){
                for(int j=1;j<iconNumber;j++)
                    if(scene->items().contains(listIcon[j])){
                        scene->removeItem(listIcon[j]);
                        listIcon[j]->setPos(0,0);
                    }
                t[i].hideRange(scene);
            }
        for(int i=0;i<towerNumber;i++)
            if(towerPlacement[i].contains(event->pos())){
                indexTower=i;
                if(t[i].isPlaced(scene)){
                    t[i].showRange(scene,true);
                    if(t[i].level<t[i].maxLevel)
                        addIcon(2);     //add upgrade
                    addIcon(1);         //add sell
                }
                else{
                    t[i].setPos(towerPositions[i]);
                    t[i].showRange(scene,false);
                    for(int j=3;j<iconNumber;j++)
                        addIcon(j);     //add tower Images
                }
            }
    }
    QGraphicsView::mousePressEvent(event);
}

void Map::addIcon(int indexListIcon)
{
    if(!scene->items().contains(listIcon[indexListIcon])){
        listIcon[indexListIcon]->setPos(findPos(indexTower));
        scene->addItem(listIcon[indexListIcon]);
    }
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
        return {0,0};
}

bool Map::isEmpty(QPointF point)
{
    for(int i=0;i<iconNumber;i++)
       if(listIcon[i]->pos()==point)
           return false;
    return true;
}
void Map::mouseMoveEvent(QMouseEvent*event)
{
    bool isInNothing=true;
    for(int i=0;i<towerNumber;i++)
        if(towerPlacement[i].contains(event->pos())){
            isInNothing=false;
            createClickableItem(towerPositions[i].x(),towerPositions[i].y(),t[i].size);
        }
    for(int i=0;i<iconNumber;i++)
        if(QRectF(listIcon[i]->x(),listIcon[i]->y(),iconSize,iconSize).contains(event->pos())&&listIcon[i]->pos()!=QPointF(0,0)){
            isInNothing = false;
            createClickableItem(listIcon[i]->x(),listIcon[i]->y(),iconSize);
            }
    if(isInNothing&&scene->items().contains(clickableItem))
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
        for(int j=3;j<iconNumber;j++){
            scene->removeItem(listIcon[j]);
            listIcon[j]->setPos(0,0);
        }
        mapUpdate();
    }
}

void Map::towerDetect()
{
    if(!vectMonster.isEmpty())
        for(int i=0;i<towerNumber;i++)
            if(t[i].isPlaced(scene)){
                int monsterToKill=0;
                QVector<Monster*>monsterTargetedList;
                for(Monster *monster : vectMonster)
                    if(t[i].hasTarget(monster))
                        monsterTargetedList.append(monster);

                if(!monsterTargetedList.isEmpty()){
                    monsterToKill=monsterTargetedList.indexOf(monsterTargetedList.first());
                    for(Monster *monster : monsterTargetedList)
                        if(monster->toCookie(path)<vectMonster.at(monsterToKill)->toCookie(path))
                            monsterToKill=monsterTargetedList.indexOf(monster);

                    if(t[i].hasTarget(vectMonster.at(vectMonster.indexOf(monsterTargetedList.at(monsterToKill)))))
                        new Projectile(&t[i],scene,vectMonster.at(vectMonster.indexOf(monsterTargetedList.at(monsterToKill))));
                }
            }
}

void Map::aliveMonster()
{
    if(!vectMonster.isEmpty())
        for(Monster *monster : vectMonster)
            if(monster->hp<=0){
                money+=monster->reward;
                scene->removeItem(monster->rectRed);
                scene->removeItem(monster->rectGreen);
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
        for(Monster * monster : vectMonster)
            monster->move(path,&health);
    mapUpdate();
}

void Map::addMonster(char x)
{
    vectMonster.append(new Monster(x));
    vectMonster.last()->setPos(path.first().toPoint());
    scene->addItem(vectMonster.last());
    scene->addItem(vectMonster.last()->rectRed);
    scene->addItem(vectMonster.last()->rectGreen);

}

int waveCodeTest(int i,QString waveCode,char x)
{
    QString string;
    if(waveCode.at(i)==x){
        for(int j=i+1;j<waveCode.size() && waveCode.at(j)!=x && waveCode.at(j).isDigit();j++)
            if(waveCode.at(j).isDigit())
                string.append(waveCode.at(j));
        return string.toInt();
    }
    return 0;
}

void Map::spawnMonster()
{
    if(difficulty==0){
        int x=qrand()%numberOfMonster;
        if(infiniteSpawn%2==1)
            addMonster(QChar(65+x).toLatin1());
        else if(infiniteSpawn%3==2 )
            addMonster(QChar(65+x).toLatin1());
        infiniteSpawn++;
    }
    else{
        for(int i=0;i<=numberOfMonster-1;i++){
            if(waveTab[i]>0){
                addMonster(QChar(65+i).toLatin1());
                waveTab[i]--;
            }
        }
            timerSpawn->setInterval(500);
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
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream flow(&file);
            for(int i=0;i<this->waveIndex;i++)
                waveCode=flow.readLine();
            file.close();
            for(int j=0;j<=numberOfMonster-1;j++)
                for(int i=0;i<waveCode.size();i++)
                    waveTab[j]+=waveCodeTest(i,waveCode,QChar(65+j).toLatin1());
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
    if(health>0){
        textMoney->setText(QString("Money: ")+QString::number(money));
        textHealth->setText(QString::number(int(health)));
        rectGreen->setRect(0,0,((width/5)-(((stackHealth-health)/stackHealth)*(width/5))),40);
    }
    if(health<=0)
        gameOver();
}

void Map::gameOver()
{
    timer->stop();
    timerWave->stop();
    timerTower->stop();
    vectMonster.clear();
    textHealth->setText("0");
    delete rectGreen;
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
    if(remainingTimeWave>0)
        remainingTimeWave=timerWave->remainingTime();
    timerWave->stop();
    if(remainingTimeSpawn>0)
        remainingTimeSpawn=timerSpawn->remainingTime();
    timerSpawn->stop();
    timerTower->stop();
    emit pauseFunction();
}

void Map::hideUpgradeSell()
{
    for(int i=1;i<numberOfTowerLvl;i++){
        scene->removeItem(listIcon[i]);
        listIcon[i]->setPos(0,0);
    }
    t[indexTower].hideRange(scene);
    mapUpdate();
}
