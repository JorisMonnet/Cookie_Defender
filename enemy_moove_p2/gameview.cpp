#include "gameview.h"

GameView::GameView(QWidget*parent,Map*map) : QWidget(parent)
{
    setMouseTracking(true);
    //mainLay->setContentsMargins(0,0,0,0);

    towerMenu= new TowerMenu();
    mainLay=new QVBoxLayout();

    if(map!=nullptr){
        this->map=new Map(nullptr,map->path,map->towerNumber,map->towerPositions,map->money,new QGraphicsPixmapItem(map->background->pixmap()));
        mainLay->addWidget(map);
    }
    setLayout(mainLay);
}

void GameView::showTowerMenu()
{
    mainLay->addWidget(towerMenu);
}

void GameView::showOnlyMap()
{
    mainLay->removeWidget(towerMenu);
}
