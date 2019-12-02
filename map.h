#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsScene>
#include <QMouseEvent>
#include "tower.h"

class Map : public QGraphicsView
{
public:
    Map(QGraphicsView * parent=nullptr);  
    void createTower(int index);
    void showRange(int index);
protected slots:
    void mousePressEvent(QMouseEvent *event) override;
private:
    QPoint start={0,500};
    QGraphicsScene *scene;
    QPoint towerPositions[4]={{50,350},{500,350},{300,550},{700,550}};
    bool towerCreated[4];
    QGraphicsEllipseItem showedRange;
    QGraphicsRectItem towerPlacement[4];
    int money=400;
    int health=20;
    Tower t[4];
};

#endif // MAP_H
