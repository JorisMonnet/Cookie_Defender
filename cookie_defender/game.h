#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QStackedWidget>
#include "mainmenu.h"
#include "mapmenu.h"
#include "map.h"
#include "story.h"
#include "difficultymenu.h"
#include "encyclopedia.h"

/**
* Class which manage the widget shown at the player
* widget which can be shown : story/difficultyMenu/mapMenu/pauseMenu/encycmopedia/map
* it also play the game sounds
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
*/

class Game : public QMainWindow
{
    Q_OBJECT
public:
    Game(QMainWindow*parent=nullptr);
private slots :
    void resume(void);
    void pause(void);
    void chooseMap(int indexMap=1);
    void startMap(void);
private:
    void menu(void);
    void setGame(void);

    MainMenu *mainMenu;
    PauseMenu*pauseMenu;
    MapMenu*mapMenu;
    DifficultyMenu *difficultyMenu;
    QStackedWidget *stackedWidget;
    Encyclopedia *encyclopedia;
    Map *currentMap;
    Story *story;
    int indexMap;
    int musicVolume=50,soundVolume=50;
    int lastIndex=0;
    int difficulty=0;
};

#endif // GAME_H
