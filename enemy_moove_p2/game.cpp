#include "game.h"

Game::Game(QMainWindow *parent) : QMainWindow(parent)
{
    setWindowTitle("Cookie Defender");
    setFixedSize(1000,1000);
    setGame();
    menu();
}
void Game::setGame()
{
    map1 = new Map();
    pauseMenu = new PauseMenu();
    mainMenu = new MainMenu();
    mapMenu = new MapMenu();
    difficultyMenu = new DifficultyMenu();
    encyclopedia = new Encyclopedia();
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(mainMenu);
    stackedWidget->addWidget(map1);
    stackedWidget->addWidget(pauseMenu);
    stackedWidget->addWidget(encyclopedia);
    stackedWidget->addWidget(mapMenu);
    stackedWidget->addWidget(difficultyMenu);
    setCentralWidget(stackedWidget);

    connect(difficultyMenu,&DifficultyMenu::exitDifficultyMenu,this,[=]{stackedWidget->setCurrentIndex(4);});
    connect(difficultyMenu,&DifficultyMenu::difficultySignal,this,&Game::restartMap);
    connect(map1,&Map::pauseFunction,this,&Game::pause);
    connect(pauseMenu->resume,&QPushButton::clicked,this,&Game::resume);
    connect(pauseMenu->exit,&QPushButton::clicked,map1,&Map::gameOver);
    connect(pauseMenu->encyclo,&QPushButton::clicked,this,&Game::encyclo);
    connect(mainMenu->play,&QPushButton::clicked,this,[=]{stackedWidget->setCurrentIndex(4);});
    connect(encyclopedia,&Encyclopedia::finishEncyclo,this,[=]{stackedWidget->setCurrentIndex(lastIndex);});
    //connect(mainMenu->options,&QPushButton::clicked,this,&Game::?);
    connect(mainMenu->encyclo,&QPushButton::clicked,this,&Game::encyclo);
    connect(map1,&Map::gameEnd,this,&Game::menu);
    connect(pauseMenu->restart,&QPushButton::clicked,this,&Game::restartMap);
    connect(mapMenu,&MapMenu::exitMapMenu,this,&Game::menu);
    connect(mapMenu,&MapMenu::map1Chosen,this,[=]{stackedWidget->setCurrentIndex(5);});
}
void Game::restartMap(int difficulty)
{
    setGame();
    resume(difficulty);
}
void Game::resume(int difficulty)
{
    stackedWidget->setCurrentIndex(1);
    map1->timer->start(15);
    map1->timerSpawn->start(5000);
    map1->timerWave->start(30000);
}
void Game::encyclo()
{
    stackedWidget->setCurrentIndex(3);
}
void Game::menu()
{
    lastIndex=0;
    stackedWidget->setCurrentIndex(0);
}
void Game::pause()
{
    lastIndex=2;
    stackedWidget->setCurrentIndex(2);
}
