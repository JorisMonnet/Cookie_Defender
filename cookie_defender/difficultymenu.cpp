#include "difficultymenu.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

DifficultyMenu::DifficultyMenu(QWidget * parent): QWidget(parent)
{
    QPushButton *easy = new QPushButton(tr("E&asy"));
    QPushButton *medium = new QPushButton(tr("&Medium"));
    QPushButton *hard = new QPushButton(tr("&Hard"));
    QPushButton *infinite = new QPushButton(tr("&Infinite"));
    QPushButton *exit = new QPushButton(tr("&Exit"));

    QButtonGroup * group = new QButtonGroup(this);
    group->addButton(easy);
    group->setId(easy,1);
    group->addButton(medium);
    group->setId(medium,2);
    group->addButton(hard);
    group->setId(hard,3);
    group->addButton(infinite);
    group->setId(infinite,0);

    QVBoxLayout *vLay = new QVBoxLayout();
    vLay->addStretch();
    vLay->addWidget(easy);
    vLay->addWidget(medium);
    vLay->addWidget(hard);
    vLay->addWidget(infinite);
    vLay->addStretch();
    vLay->addWidget(exit);
    vLay->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(vLay);
    mainLayout->addStretch();
    connect(group, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),[=](int id){
        emit difficultySignal(id);
    });
    connect(exit,&QPushButton::clicked,this,[=]{emit exitDifficultyMenu();});
}
