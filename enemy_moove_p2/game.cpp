#include "game.h"

Game::Game(QMainWindow *parent) : QMainWindow(parent)
{
    currentMap= new Map();
    setWindowTitle("Cookie Defender");
    setFixedSize(1000,1000);
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
    stackedWidget->addWidget(mainMenu);         //1 : Main Menu
    stackedWidget->addWidget(currentMap);       //2 : Map played
    stackedWidget->addWidget(pauseMenu);        //3 : Pause Menu
    stackedWidget->addWidget(encyclopedia);     //4 : Encyclopedia
    stackedWidget->addWidget(mapMenu);          //5 : Map menu
    stackedWidget->addWidget(difficultyMenu);   //6 : difficulty Menu
    setCentralWidget(stackedWidget);

    connect(currentMap,&Map::pauseFunction,this,&Game::pause);
    connect(pauseMenu->exit,&QPushButton::clicked,currentMap,&Map::gameOver);
    connect(currentMap,&Map::gameEnd,this,&Game::menu);
    connect(difficultyMenu,&DifficultyMenu::exitDifficultyMenu,this,[=]{stackedWidget->setCurrentWidget(mapMenu);});
    connect(difficultyMenu,&DifficultyMenu::difficultySignal,this,&Game::restartMap);
    connect(pauseMenu->resume,&QPushButton::clicked,this,&Game::resume);
    connect(pauseMenu->encyclo,&QPushButton::clicked,this,&Game::encyclo);
    connect(mainMenu->play,&QPushButton::clicked,this,[=]{stackedWidget->setCurrentWidget(mapMenu);});
    connect(encyclopedia,&Encyclopedia::finishEncyclo,this,[=]{stackedWidget->setCurrentIndex(lastIndex);});
    //connect(mainMenu->options,&QPushButton::clicked,this,&Game::?);
    connect(mainMenu->encyclo,&QPushButton::clicked,this,&Game::encyclo);
    connect(pauseMenu->restart,&QPushButton::clicked,this,&Game::restartMap);
    connect(mapMenu,&MapMenu::exitMapMenu,this,&Game::menu);
    connect(mapMenu,&MapMenu::mapChosen,this,&Game::chooseMap);
}
void Game::chooseMap(int indexMap)
{
    QVector<QPointF> path;
    int towerNumber=4,money=500;
    QPoint *towerPositions= new QPoint;
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem;
    switch(indexMap){
    case 1: path<<QPointF(0,475)<<QPointF(200,475)<<QPointF(200,700)<<QPointF(70,700)
                <<QPointF(70,850)<<QPointF(450,850)<<QPointF(450,300)<<QPointF(650,300)
                <<QPointF(650,475)<<QPointF(950,475);
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
    stackedWidget->setCurrentWidget(difficultyMenu);
}
void Game::restartMap(int difficulty)
{
    setGame();
    resume(difficulty);
}
void Game::resume(int difficulty)
{
    difficulty=0;//useless
    stackedWidget->setCurrentWidget(currentMap);
    currentMap->timer->start(15);
    currentMap->timerSpawn->start(2000);
}
void Game::encyclo()
{
    stackedWidget->setCurrentWidget(encyclopedia);
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
