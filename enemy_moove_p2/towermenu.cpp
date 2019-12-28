#include "towermenu.h"

TowerMenu::TowerMenu(QGraphicsView *parent): QGraphicsView(parent)
{
    QGraphicsScene * scene = new QGraphicsScene(this);
    setSceneRect(QRect(0,0,1000,200));
    setScene(scene);
    Tower *t = new Tower;
    QGraphicsPixmapItem * tower1 = new QGraphicsPixmapItem(QPixmap(t->pixmap()).scaled(50,50));
    tower1->setPos(10,10);
    QGraphicsTextItem * textTower1 = new QGraphicsTextItem(tr("Tower 1"));
    textTower1->setPos(10,60);
    scene->addItem(tower1);
    scene->addItem(textTower1);
}
