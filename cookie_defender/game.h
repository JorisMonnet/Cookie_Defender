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
* Description of the class
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
* @version	Number of the version
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
