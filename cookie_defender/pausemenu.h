#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QPushButton>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "soundboxes.h"

/**
* Description of the class
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
* @version	Number of the version
*/

class PauseMenu : public QWidget
{
    Q_OBJECT
public:
    PauseMenu(QWidget *parent = nullptr,int musicVolume=50,int soundsEffectVolume=50);
    QPushButton *resume,*restart,*encyclo,*exit;
    SoundBoxes *sounds;
    QMediaPlayer *soundEnemyTP,*soundMoney,*soundGameWin,*soundGameOver;
    void manageMusic(bool);
private:
    void keyPressEvent(QKeyEvent*) override;
};

#endif // PAUSEMENU_H
