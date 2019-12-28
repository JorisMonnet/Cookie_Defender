#include "towermenu.h"

TowerMenu::TowerMenu(QGraphicsView *parent): QGraphicsView(parent)
{
    setFixedSize(1000,200);
    QGraphicsScene * scene = new QGraphicsScene(this);
    Tower *t = new Tower;
    QGraphicsPixmapItem * tower1 = new QGraphicsPixmapItem(QPixmap(t->pixmap()).scaled(25,25));
    tower1->setPos(10,10);
    QGraphicsTextItem * textTower1 = new QGraphicsTextItem(tr("Tower 1"));
    textTower1->setPos(10,45);
    scene->addItem(tower1);
    scene->addItem(textTower1);
}
