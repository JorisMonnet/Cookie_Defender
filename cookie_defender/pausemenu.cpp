#include "pausemenu.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

PauseMenu::PauseMenu(QWidget *parent,int musicVolume,int soundsEffectVolume): QWidget(parent)
{
    resume = new QPushButton(tr("&Resume"));
    restart = new QPushButton(tr("Re&start"));
    encyclo = new QPushButton(tr("&Encyclopedia"));
    exit = new QPushButton(tr("To &main menu"));
    sounds = new SoundBoxes(nullptr,musicVolume,soundsEffectVolume);
    sounds->music->setMedia(QUrl("../sounds/jeu_versiofull.wav"));
    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addStretch();
    vLay->addWidget(resume);
    vLay->addWidget(restart);
    vLay->addWidget(encyclo);
    vLay->addWidget(sounds);
    vLay->addWidget(exit);
    vLay->addStretch();

    QHBoxLayout *mainLay = new QHBoxLayout();
    mainLay->addStretch();
    mainLay->addLayout(vLay);
    mainLay->addStretch();
    setLayout(mainLay);
}
void PauseMenu::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
        emit resume->click();
}

