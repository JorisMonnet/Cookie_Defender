#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QPushButton>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "soundboxes.h"

/**
* Menu of pause when pause icon or escape key are clicked on from the map
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
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
