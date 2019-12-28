#include "game.h"

Game::Game(QMainWindow *parent) : QMainWindow(parent)
{
    setWindowTitle("Cookie Defender");
    setFixedSize(1000,1000);
    gameView = new GameView();
    currentMap = new Map();
    currentMap->timer->stop();
    currentMap->timerSpawn->stop();
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
    stackedWidget->addWidget(gameView);
    stackedWidget->addWidget(pauseMenu);
    stackedWidget->addWidget(encyclopedia);
    stackedWidget->addWidget(mapMenu);
    stackedWidget->addWidget(difficultyMenu);
    setCentralWidget(stackedWidget);

    connect(currentMap,&Map::pauseFunction,this,&Game::pause);
    connect(currentMap,&Map::gameEnd,this,&Game::menu);
    connect(difficultyMenu,&DifficultyMenu::exitDifficultyMenu,this,[=]{stackedWidget->setCurrentWidget(mapMenu);});
    connect(difficultyMenu,&DifficultyMenu::difficultySignal,this,&Game::startMap);
    connect(pauseMenu->resume,&QPushButton::clicked,this,&Game::resume);
    connect(pauseMenu->restart,&QPushButton::clicked,this,&Game::restartMap);
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
    switch(indexMap){
        case 1: path<<QPointF(0,475)<<QPointF(200,475)<<QPointF(200,700)<<QPointF(70,700)<<QPointF(70,850)
                    <<QPointF(450,850)<<QPointF(450,300)<<QPointF(650,300)<<QPointF(650,475)<<QPointF(950,475);
                towerNumber=4;
                background->setPixmap(QPixmap("../icones/bg.jpg").scaled(1000,1000));
                towerPositions=new QPoint[towerNumber];
                towerPositions[0]= QPoint(50 ,350);
                towerPositions[1]= QPoint(500,350);
                towerPositions[2]= QPoint(300,550);
                towerPositions[3]= QPoint(700,550);
            break;

            //add case to add map
    }
    currentMap = new Map(nullptr,path,towerNumber,towerPositions,money,background);
    gameView = new GameView(nullptr,currentMap);
    stackedWidget->setCurrentWidget(difficultyMenu);
}

void Game::startMap(int difficulty)
{
    this->difficulty=difficulty;
    setGame();
    resume();
}

void Game::restartMap()
{
    chooseMap(indexMap);
}

void Game::resume()
{
    stackedWidget->setCurrentWidget(gameView);
    currentMap->timer->start(15);
    currentMap->timerSpawn->start(2000);
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
