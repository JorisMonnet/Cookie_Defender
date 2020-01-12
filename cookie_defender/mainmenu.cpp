#include "mainmenu.h"
#include "soundboxes.h"
#include <QLabel>

#include <QVBoxLayout>

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
{
    play = new QPushButton(tr("&Play"));
    encyclo = new QPushButton(tr("&Encyclopedia"));
    options = new QPushButton(tr("&Options"));
    story = new QPushButton(tr("The Cookie &Story"));

    SoundBoxes *sounds = new SoundBoxes(this);

    QPushButton *exit = new QPushButton(tr("Exit game"));
    QPixmap pix("../icones/logo2.png");
    QLabel *lab=new QLabel();
    lab->setPixmap(pix.scaled(2*this->width()/3,2*this->height()/3,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addStretch();
    vLay->addWidget(play);
    vLay->addWidget(encyclo);
    vLay->addWidget(options);
    vLay->addWidget(sounds);
    vLay->addWidget(story);
    vLay->addWidget(exit);
    vLay->addWidget(lab);
    vLay->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(vLay);
    mainLayout->addStretch();

    connect(exit, &QPushButton::clicked, this, &QApplication::quit);
}
