#include "mapmenu.h"

MapMenu::MapMenu(QWidget *parent): QWidget(parent)
{
    QVBoxLayout * vLay = new QVBoxLayout();
    QHBoxLayout * mainLay = new QHBoxLayout(this);
    QButtonGroup * mapGroup = new QButtonGroup();

    map1 = new QPushButton(tr("Map &Grass"));
    map2 = new QPushButton(tr("Map &Sand"));
    exit = new QPushButton(tr("&Exit"));

    QPixmap grass(":/icones/miniaGrass.png");
    QPixmap sand(":/icones/miniaSand.png");
    QLabel *labPixSand=new QLabel();
    QLabel *labPixGrass=new QLabel();
    labPixSand->setPixmap(sand.scaled(2*this->width()/3,this->height()/3,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));
    labPixGrass->setPixmap(grass.scaled(2*this->width()/3,this->height()/3,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));

    mapGroup->addButton(map1);
    mapGroup->setId(map1,1);
    mapGroup->addButton(map2);
    mapGroup->setId(map2,2);
    vLay->addStretch();

    vLay->addStretch();
    vLay->addWidget(labPixGrass);
    vLay->addWidget(map1);
    vLay->addStretch();
    vLay->addWidget(labPixSand);
    vLay->addWidget(map2);
    vLay->addStretch();
    vLay->addWidget(exit);
    vLay->addStretch();

    mainLay->addStretch();
    mainLay->addLayout(vLay);
    mainLay->addStretch();

    connect(exit,&QPushButton::clicked,this,[=]{emit exitMapMenu();});
    connect(mapGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),[=](int indexMap){
        emit mapChosen(indexMap);
    });
}
