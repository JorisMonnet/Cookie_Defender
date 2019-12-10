#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QStackedWidget>
#include "pausemenu.h"
#include "map.h"
#include "mainmenu.h"

class Game : public QMainWindow
{
    Q_OBJECT
public:
    Game(QMainWindow*parent=nullptr);
    Map *map1;
    void menu();
    void setGame();
    MainMenu *mainMenu;
    PauseMenu*pauseMenu;
    QStackedWidget *stackedWidget;
public slots :
    void resume();
    void encyclo();
    void pause();
    void restartMap();
};

#endif // GAME_H
