#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include "soundboxes.h"

class MainMenu : public QWidget
{
public:
    MainMenu(QWidget *parent = nullptr,int musicVolume=50,int SoundEffectVolume=50);
    QPushButton *options;
    QPushButton *encyclo;
    QPushButton *play;
    QPushButton *story;
    SoundBoxes *sounds;
};

#endif // MAINMENU_H
