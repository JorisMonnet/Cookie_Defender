#include "gameview.h"

GameView::GameView(QWidget*parent,Map*map) : QWidget(parent)
{
    mainLay=new QVBoxLayout();
    setFixedSize(1000,1000);
    setMouseTracking(true);
    mainLay->setContentsMargins(0,0,0,0);
    mainLay->setSpacing(0);
    if(map!=nullptr){
        this->map=new Map(nullptr,map->path,map->towerNumber,map->towerPositions,map->money,new QGraphicsPixmapItem(map->background->pixmap()));
        mainLay->addWidget(map);
        towerMenu= new TowerMenu(nullptr,map->towerClicked);

        connect(map,&Map::clickedTower,[=]{
            if(mainLay->count()<2){
                towerMenu= new TowerMenu(nullptr,map->towerClicked);
                mainLay->addWidget(towerMenu);
            }
        });
        connect(towerMenu,&TowerMenu::finished,this,[=]{mainLay->removeWidget(towerMenu);});
    }
    setLayout(mainLay);
}
