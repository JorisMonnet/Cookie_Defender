#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QStackedWidget>
#include "pausemenu.h"
#include "mainmenu.h"
#include "mapmenu.h"
#include "difficultymenu.h"
#include "encyclopedia.h"
#include "gameview.h"

class Game : public QMainWindow
{
    Q_OBJECT
public:
    Game(QMainWindow*parent=nullptr);
private slots :
    void resume();
    void pause();
    void restartMap();
    void chooseMap(int indexMap=1);
    void startMap(int difficulty);
private:
    void menu();
    void setGame();
    GameView *gameView;
    MainMenu *mainMenu;
    PauseMenu*pauseMenu;
    MapMenu*mapMenu;
    DifficultyMenu *difficultyMenu;
    QStackedWidget *stackedWidget;
    Encyclopedia *encyclopedia;
    Map *currentMap;
    int indexMap;
    int lastIndex=0;
    int difficulty=0;
};

#endif // GAME_H
