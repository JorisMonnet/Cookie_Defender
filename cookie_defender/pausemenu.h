#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QWidget>
#include <QPushButton>
#include "soundboxes.h"
class PauseMenu : public QWidget
{
    Q_OBJECT
public:
    PauseMenu(QWidget *parent = nullptr);
    QPushButton *resume;
    QPushButton *restart;
    QPushButton * encyclo;
    QPushButton *exit;
    SoundBoxes *sounds;
};
#endif // PAUSEMENU_H
