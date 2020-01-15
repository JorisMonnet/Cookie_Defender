#ifndef MAINMENU_H
#define MAINMENU_H

#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include "soundboxes.h"

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
