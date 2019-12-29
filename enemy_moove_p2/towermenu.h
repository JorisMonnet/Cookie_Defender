#ifndef TOWERMENU_H
#define TOWERMENU_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "tower.h"

class TowerMenu : public QGraphicsView
{
    Q_OBJECT
public:
    TowerMenu(QGraphicsView*parent=nullptr,Tower*t=nullptr);
    void mousePressEvent(QMouseEvent *event) override;
signals :
    void finished();
private :
    QGraphicsPixmapItem *tower1;
    QGraphicsPixmapItem *upgrade;
    QGraphicsPixmapItem *sell;
    const int towerMaxLevel = 3;
    QGraphicsScene * scene;
};

#endif // TOWERMENU_H
