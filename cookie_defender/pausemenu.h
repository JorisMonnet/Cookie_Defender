#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QWidget>
#include <QPushButton>
#include <QKeyEvent>
#include "soundboxes.h"
class PauseMenu : public QWidget
{
    Q_OBJECT
public:
    PauseMenu(QWidget *parent = nullptr,int musicVolume=50,int soundsEffectVolume=50);
    QPushButton *resume;
    QPushButton *restart;
    QPushButton * encyclo;
    QPushButton *exit;
    SoundBoxes *sounds;
    void manageMusic(bool play);
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // PAUSEMENU_H
