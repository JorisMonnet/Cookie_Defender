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
    encyclopedia = new Encyclopedia();
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(mainMenu);
    stackedWidget->addWidget(map1);
    stackedWidget->addWidget(pauseMenu);
    stackedWidget->addWidget(encyclopedia);
    setCentralWidget(stackedWidget);
    connect(map1,&Map::pauseFunction,this,&Game::pause);
    connect(pauseMenu->resume,&QPushButton::clicked,this,&Game::resume);
    connect(pauseMenu->exit,&QPushButton::clicked,map1,&Map::gameOver);
    connect(pauseMenu->encyclo,&QPushButton::clicked,this,&Game::encyclo);
    connect(mainMenu->play,&QPushButton::clicked,this,&Game::restartMap);
    connect(encyclopedia,&Encyclopedia::finishEncyclo,this,[=]{stackedWidget->setCurrentIndex(lastIndex);});
    //connect(mainMenu->options,&QPushButton::clicked,this,&Game::?);
    connect(mainMenu->encyclo,&QPushButton::clicked,this,&Game::encyclo);
    connect(map1,&Map::gameEnd,this,&Game::menu);
    connect(pauseMenu->restart,&QPushButton::clicked,this,&Game::restartMap);
}
void Game::restartMap()
{
    setGame();
    resume();
}
void Game::resume()
{
    stackedWidget->setCurrentIndex(1);
    map1->timer->start(15);
    map1->timerSpawn->start(2000);
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
