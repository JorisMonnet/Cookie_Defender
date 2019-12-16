#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QStackedWidget>
#include "pausemenu.h"
#include "map.h"
#include "mainmenu.h"
#include "mapmenu.h"
#include "difficultymenu.h"
#include "encyclopedia.h"

class Game : public QMainWindow
{
    Q_OBJECT
public:
    Game(QMainWindow*parent=nullptr);
    void menu();
    void setGame();
private slots :
    void resume(int difficulty);
    void encyclo();
    void pause();
    void restartMap(int difficulty);
private:
    int lastIndex=0;
    MainMenu *mainMenu;
    PauseMenu*pauseMenu;
    MapMenu*mapMenu;
    DifficultyMenu *difficultyMenu;
    QStackedWidget *stackedWidget;
    Encyclopedia *encyclopedia;
    Map *map1;
};

#endif // GAME_H
