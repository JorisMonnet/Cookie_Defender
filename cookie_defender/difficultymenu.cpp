#include "difficultymenu.h"

DifficultyMenu::DifficultyMenu(QWidget * parent): QWidget(parent)
{
    QPushButton **listButton = new QPushButton*[4];
    listButton[0] = new QPushButton(tr("&Infinite"));
    listButton[1] = new QPushButton(tr("E&asy"));
    listButton[2] = new QPushButton(tr("&Medium"));
    listButton[3] = new QPushButton(tr("&Hard"));
    QPushButton *exit = new QPushButton(tr("&Exit"));

    QButtonGroup * group = new QButtonGroup(this);
    for(int i=0;i<4;i++){
        group->addButton(listButton[i]);
        group->setId(listButton[i],i);
    }

    QVBoxLayout *vLay = new QVBoxLayout();
    vLay->addStretch();
    for(int i=1;i<4;i++)
        vLay->addWidget(listButton[i]);
    vLay->addWidget(listButton[0]);
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
