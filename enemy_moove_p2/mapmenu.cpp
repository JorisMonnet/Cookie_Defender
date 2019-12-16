#include "mapmenu.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
MapMenu::MapMenu(QWidget *parent): QWidget(parent)
{
    QVBoxLayout * vLay = new QVBoxLayout();
    QHBoxLayout * mainLay = new QHBoxLayout(this);
    map1 = new QPushButton(tr("Map Grass"));
    exit = new QPushButton(tr("Exit"));
    vLay->addStretch();
    vLay->addWidget(map1);
    vLay->addWidget(exit);
    vLay->addStretch();
    mainLay->addStretch();
    mainLay->addLayout(vLay);
    mainLay->addStretch();
    connect(exit,&QPushButton::clicked,this,[=]{emit exitMapMenu();});
    connect(map1,&QPushButton::clicked,this,[=]{emit map1Chosen();});
}
