#include "towermenu.h"

TowerMenu::TowerMenu(QGraphicsView *parent,Tower *t): QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setSceneRect(QRect(0,0,1000,100));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    if(t==nullptr){
        tower1 = new QGraphicsPixmapItem(QPixmap("../icones/tower1.png").scaled(50,50));
        tower1->setPos(10,10);
        QGraphicsTextItem * textTower1 = new QGraphicsTextItem(tr("Tower 1"));
        textTower1->setPos(10,60);
        scene->addItem(textTower1);
        scene->addItem(tower1);
    }

    upgrade = new QGraphicsPixmapItem(QPixmap("../icones/upgrade.png").scaled(50,50));
    sell = new QGraphicsPixmapItem(QPixmap("../icones/sell.png").scaled(50,50));
    upgrade->setPos(70,10);
    sell->setPos(130,10);

    QGraphicsTextItem *textUpgrade = new QGraphicsTextItem(tr("Upgrade"));
    QGraphicsTextItem *textSell = new QGraphicsTextItem("Sell"); // want to put the amount received for a sold

    textUpgrade->setPos(70,60);
    textSell->setPos(130,60);
    scene->addItem(upgrade);
    scene->addItem(sell);
    scene->addItem(textUpgrade);
    scene->addItem(textSell);
}

void TowerMenu::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(scene->items().contains(tower1)&&tower1->contains(event->pos())){

        }
    emit finished();
    }
}
