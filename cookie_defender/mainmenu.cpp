#include "mainmenu.h"
#include "soundboxes.h"

#include <QVBoxLayout>

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
{
    play = new QPushButton(tr("Play"));
    encyclo = new QPushButton(tr("Encyclopedia"));
    options = new QPushButton(tr("Options"));

    SoundBoxes *sounds = new SoundBoxes(this);

    QPushButton *exit = new QPushButton(tr("Exit game"));

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addStretch();
    vLay->addWidget(play);
    vLay->addWidget(encyclo);
    vLay->addWidget(options);
    vLay->addWidget(sounds);
    vLay->addWidget(exit);
    vLay->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addStretch(5);
    mainLayout->addLayout(vLay);
    mainLayout->addStretch(5);

    connect(exit, &QPushButton::clicked, this, &QApplication::quit);
}
