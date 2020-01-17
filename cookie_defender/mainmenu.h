#ifndef MAINMENU_H
#define MAINMENU_H

#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include "soundboxes.h"

/**
* Menu where the player begin, from this, the player can play,
* read the story/the encyclopedia, manage the sounds volume or exit the game
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
*/

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    MainMenu(QWidget *parent = nullptr,int musicVolume=50,int SoundEffectVolume=50);
    void manageMusic(bool play);

    QPushButton *encyclo,*play,*story;
    SoundBoxes *sounds;

private slots:
    void playSound(void);
};

#endif // MAINMENU_H
