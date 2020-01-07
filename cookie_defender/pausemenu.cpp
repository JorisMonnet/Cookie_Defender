#include "pausemenu.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

PauseMenu::PauseMenu(QWidget *parent): QWidget(parent)
{
    resume = new QPushButton(tr("resume"));
    restart = new QPushButton(tr("Restart"));
    encyclo = new QPushButton(tr("Encyclopedia"));
    exit = new QPushButton(tr("To main menu"));
    sounds = new SoundBoxes(this);

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addStretch();
    vLay->addWidget(resume);
    vLay->addWidget(restart);
    vLay->addWidget(encyclo);
    vLay->addWidget(sounds);
    vLay->addWidget(exit);
    vLay->addStretch();

    QHBoxLayout *mainLay = new QHBoxLayout(this);
    mainLay->addStretch();
    mainLay->addLayout(vLay);
    mainLay->addStretch();

}
void PauseMenu::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
        emit resume->click();
}

