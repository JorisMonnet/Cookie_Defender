#include "game.h"
#include <QFile>
#include <QTextStream>
#include <QString>
Game::Game(QMainWindow *parent) : QMainWindow(parent)
{
    setWindowTitle("Cookie Defender");
    setFixedSize(1000,1000);
    currentMap = new Map();
    currentMap->timer->stop();
    currentMap->timerSpawn->stop();
    currentMap->timerWave->stop();
    currentMap->timerTower->stop();
    setGame();
    menu();
}

void Game::setGame()
{
    pauseMenu = new PauseMenu();
    mainMenu = new MainMenu();
    mapMenu = new MapMenu();
    difficultyMenu = new DifficultyMenu();
    encyclopedia = new Encyclopedia();
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(mainMenu);
    stackedWidget->addWidget(currentMap);
    stackedWidget->addWidget(pauseMenu);
    stackedWidget->addWidget(encyclopedia);
    stackedWidget->addWidget(mapMenu);
    stackedWidget->addWidget(difficultyMenu);
    setCentralWidget(stackedWidget);

    QPalette pal = palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap("../icones/menubg.png")));
    stackedWidget->setAutoFillBackground(true);
    stackedWidget->setPalette(pal);
    //stackedWidget->setStyleSheet(QString("background-image:url(%1)").arg("../icones/menubg.png"));


    connect(currentMap,&Map::pauseFunction,this,&Game::pause);
    connect(currentMap,&Map::gameEnd,this,&Game::menu);
    connect(difficultyMenu,&DifficultyMenu::exitDifficultyMenu,this,[=]{stackedWidget->setCurrentWidget(mapMenu);});
    connect(difficultyMenu,&DifficultyMenu::difficultySignal,this,&Game::startMap);
    connect(pauseMenu->resume,&QPushButton::clicked,this,&Game::resume);
    connect(pauseMenu->restart,&QPushButton::clicked,this,[=]{chooseMap(indexMap);});
    connect(pauseMenu->encyclo,&QPushButton::clicked,this,[=]{stackedWidget->setCurrentWidget(encyclopedia);});
    connect(pauseMenu->exit,&QPushButton::clicked,currentMap,&Map::gameOver);
    connect(mainMenu->play,&QPushButton::clicked,this,[=]{stackedWidget->setCurrentWidget(mapMenu);});
    //connect(mainMenu->options,&QPushButton::clicked,this,&Game::?);
    connect(mainMenu->encyclo,&QPushButton::clicked,this,[=]{stackedWidget->setCurrentWidget(encyclopedia);});
    connect(encyclopedia,&Encyclopedia::finishEncyclo,this,[=]{stackedWidget->setCurrentIndex(lastIndex);});
    connect(mapMenu,&MapMenu::exitMapMenu,this,&Game::menu);
    connect(mapMenu,&MapMenu::mapChosen,this,&Game::chooseMap);
}
void Game::chooseMap(int indexMap)
{
    QVector<QPointF> path;
    int towerNumber=4,money=500;
    QPoint *towerPositions= new QPoint;
    this->indexMap=indexMap;
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem;
    background->setPixmap(QPixmap(QString("../icones/bg%1.jpg").arg(indexMap)).scaled(1000,1000));
    QFile fichier(QString("../maps/map%1.txt").arg(indexMap));
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        money = flux.readLine().toInt();
        towerNumber = flux.readLine().toInt();
        towerPositions=new QPoint[towerNumber];
        for(int i=0;i<towerNumber;i++){
            QString Line =flux.readLine();
            int j= Line.indexOf(',');
            towerPositions[i]=QPoint(Line.left(j).toInt(),Line.right(Line.size()-j-1).toInt());
        }
        while(!flux.atEnd()){
            QString Line = flux.readLine();
            int j= Line.indexOf(',');
            path << QPoint(Line.left(j).toInt(),Line.right(Line.size()-j-1).toInt());
        }
        fichier.close();
    }
    else{
        //implements if the map doesn't exist
    }
    currentMap = new Map(nullptr,path,towerNumber,towerPositions,money,background);
    stackedWidget->setCurrentWidget(difficultyMenu);
}

void Game::startMap(int difficulty)
{
    this->difficulty=difficulty;
    setGame();
    resume();
}

void Game::resume()
{
    stackedWidget->setCurrentWidget(currentMap);
    currentMap->timer->start(15);
    currentMap->timerSpawn->start(2000);
    currentMap->timerWave->start(50000);
    currentMap->timerTower->start(200);
    }

void Game::menu()
{
    lastIndex=0;
    stackedWidget->setCurrentWidget(mainMenu);
}

void Game::pause()
{
    lastIndex=2;
    stackedWidget->setCurrentWidget(pauseMenu);
}
