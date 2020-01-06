#include "difficultymenu.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>

DifficultyMenu::DifficultyMenu(QWidget * parent): QWidget(parent)
{
    QPushButton *easy = new QPushButton(tr("Easy"));
    QPushButton *medium = new QPushButton(tr("Medium"));
    QPushButton *hard = new QPushButton(tr("Hard"));
    QPushButton *exit = new QPushButton(tr("Exit"));

    QButtonGroup * group = new QButtonGroup(this);
    group->addButton(easy);
    group->addButton(medium);
    group->addButton(hard);

    QVBoxLayout *vLay = new QVBoxLayout();
    vLay->addStretch(5);
    vLay->addWidget(easy);
    vLay->addWidget(medium);
    vLay->addWidget(hard);
    vLay->addStretch(5);
    vLay->addWidget(exit);
    vLay->addStretch(5);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addStretch(5);
    mainLayout->addLayout(vLay);
    mainLayout->addStretch(5);
    connect(group, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),[=](int id){
        emit difficultySignal(id);
    });
    connect(exit,&QPushButton::clicked,this,[=]{emit exitDifficultyMenu();});
}
