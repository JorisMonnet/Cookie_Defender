#include "game.h"
#include <QTextStream>
#include <QString>


Game::Game(QMainWindow *parent) : QMainWindow(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    currentMap = new Map();
    mainMenu = new MainMenu();
    pauseMenu = new PauseMenu();
    currentMap->timer->stop();
    currentMap->timerWave->stop();
    currentMap->timerTower->stop();
    setGame();
    menu();
}

void Game::setGame()
{
    musicVolume=mainMenu->sounds->music->volume();
    soundVolume=mainMenu->sounds->sounds->volume();
    mainMenu = new MainMenu(nullptr,pauseMenu->sounds->music->volume(),pauseMenu->sounds->sounds->volume());
    pauseMenu = new PauseMenu(nullptr,musicVolume,soundVolume);
    mapMenu = new MapMenu();
    difficultyMenu = new DifficultyMenu();
    encyclopedia = new Encyclopedia();
    story= new Story();
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(mainMenu);
    stackedWidget->addWidget(currentMap);
    stackedWidget->addWidget(pauseMenu);
    stackedWidget->addWidget(encyclopedia);
    stackedWidget->addWidget(mapMenu);
    stackedWidget->addWidget(difficultyMenu);
    stackedWidget->addWidget(story);
    setCentralWidget(stackedWidget);

    QPalette pal = palette();
    pal.setBrush(QPalette::Window,QBrush(QPixmap(":/icones/menubg.png")));
    stackedWidget->setAutoFillBackground(true);
    stackedWidget->setPalette(pal);

    connect(currentMap,&Map::pauseFunction,this,&Game::pause);
    connect(difficultyMenu,&DifficultyMenu::exitDifficultyMenu,this,[=]{
        mainMenu->sounds->sounds->play();
        menu();
    });
    connect(difficultyMenu,&DifficultyMenu::difficultySignal,this,[=](int arg){
        mainMenu->sounds->sounds->play();
        difficulty=arg;
        stackedWidget->setCurrentWidget(mapMenu);
    });
    connect(pauseMenu->resume,&QPushButton::clicked,this,[=]{
        mainMenu->sounds->sounds->play();
        resume();
    });
    connect(pauseMenu->restart,&QPushButton::clicked,this,[=]{
        mainMenu->sounds->sounds->play();
        chooseMap(indexMap);
    });
    connect(pauseMenu->encyclo,&QPushButton::clicked,this,[=]{
        mainMenu->sounds->sounds->play();
        stackedWidget->setCurrentWidget(encyclopedia);
    });
    connect(pauseMenu->exit,&QPushButton::clicked,this,[=]{
        mainMenu->sounds->sounds->play();
        currentMap->gameOver();
    });
    connect(mainMenu->play,&QPushButton::clicked,this,[=]{stackedWidget->setCurrentWidget(difficultyMenu);});
    connect(mainMenu->story,&QPushButton::clicked,this,[=]{stackedWidget->setCurrentWidget(story);});
    connect(mainMenu->encyclo,&QPushButton::clicked,this,[=]{stackedWidget->setCurrentWidget(encyclopedia);});
    connect(story,&Story::finishStory,this,[=]{
        mainMenu->sounds->sounds->play();
        stackedWidget->setCurrentWidget(mainMenu);
    });
    connect(encyclopedia,&Encyclopedia::finishEncyclo,this,[=]{
        mainMenu->sounds->sounds->play();
        stackedWidget->setCurrentIndex(lastIndex);
    });
    connect(mapMenu,&MapMenu::exitMapMenu,this,[=]{
        mainMenu->sounds->sounds->play();
        stackedWidget->setCurrentWidget(difficultyMenu);
    });
    connect(mapMenu,&MapMenu::mapChosen,this,&Game::chooseMap);
    connect(currentMap,&Map::enemyTPSound,this,[=]{pauseMenu->soundEnemyTP->play();});
    connect(currentMap,&Map::moneySound,this,[=]{pauseMenu->soundMoney->play();});
    connect(currentMap,&Map::gameWinSound,this,[=]{
        pauseMenu->manageMusic(0);
        pauseMenu->soundGameWin->play();
        stackedWidget->setCurrentWidget(mainMenu);
        connect(pauseMenu->soundGameWin,&QMediaPlayer::stateChanged,this,[=]{menu();});
    });
    connect(currentMap,&Map::gameEnd,this,[=]{
        pauseMenu->manageMusic(0);
        pauseMenu->soundGameOver->play();
        stackedWidget->setCurrentWidget(mainMenu);
        connect(pauseMenu->soundGameOver,&QMediaPlayer::stateChanged,this,[=]{menu();});
    });


}
void Game::chooseMap(int indexMap)
{
    mainMenu->sounds->sounds->play();
    QVector<QPointF> path;
    int towerNumber,money;
    QPoint *towerPositions= new QPoint;
    this->indexMap=indexMap;
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem;
    background->setPixmap(QPixmap(QString(":/icones/bg%1.jpg").arg(indexMap)).scaled(window()->width(),window()->height()));
    QFile file(QString(":/maps/map%1.txt").arg(indexMap));
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flow(&file);
        money = flow.readLine().toInt();
        towerNumber = flow.readLine().toInt();
        towerPositions=new QPoint[towerNumber];
        for(int i=0;i<towerNumber;i++){
            QString Line = flow.readLine();
            int j= Line.indexOf(',');
            towerPositions[i]=QPoint(Line.left(j).toInt(),Line.right(Line.size()-j-1).toInt());
        }
        while(!flow.atEnd()){
            QString Line = flow.readLine();
            int j = Line.indexOf(',');
            path << QPoint(Line.left(j).toInt(),Line.right(Line.size()-j-1).toInt());
        }
        file.close();
        currentMap = new Map(nullptr,path,towerNumber,towerPositions,money,background,window()->width(),window()->height(),difficulty);
        stackedWidget->addWidget(currentMap);
        startMap();
    }
    else{
        //implements if the map doesn't exist
    }
}

void Game::startMap()
{
    pauseMenu->manageMusic(0);
    mainMenu->manageMusic(0);
    pauseMenu->manageMusic(0);
    setGame();
    pauseMenu->manageMusic(0);
    pauseMenu->manageMusic(1);
    resume();
}

void Game::resume()
{    
    stackedWidget->setCurrentWidget(currentMap);
    currentMap->timer->start(15);
    currentMap->timerWave->start(currentMap->remainingTimeWave);
    currentMap->timerTower->start(1000);
    currentMap->timerSpawn->start(currentMap->remainingTimeSpawn);
}

void Game::menu()
{
    pauseMenu->manageMusic(0);
    mainMenu->manageMusic(0);
    mainMenu->manageMusic(1);
    lastIndex=0;
    if(pauseMenu->sounds->music->volume()!=50&&pauseMenu->sounds->sounds->volume()!=50){
        mainMenu->sounds->musicSlider->setValue(pauseMenu->sounds->music->volume());
        mainMenu->sounds->sfx->setValue(pauseMenu->sounds->sounds->volume());
    }
    stackedWidget->setCurrentWidget(mainMenu);
}

void Game::pause()
{
    lastIndex=2;
    stackedWidget->setCurrentWidget(pauseMenu);
}
