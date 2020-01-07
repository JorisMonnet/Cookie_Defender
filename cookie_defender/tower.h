#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "monster.h"

class Tower : public QGraphicsPixmapItem
{
public:
    Tower(QGraphicsPixmapItem *parent=nullptr);
    void showRange(QGraphicsScene *scene,bool isFilled);
    void hideRange(QGraphicsScene *scene);
    void set(int level);
    void shotTower(Monster*target);
    bool hasTarget(Monster*target);
    bool isPlaced(QGraphicsScene *scene);
    QLine getAimLine(Monster *target);

    int damage;
    int range;
    int cost=100;
    int speed;
    int level;
    int type=1;   //type 1 = classsic tower type 2 = mageTower
    const int towerSize=100;
    const int maxLevel = 3;
    bool isShowingRange=false;
    QGraphicsEllipseItem *showedRange=nullptr;
};

#endif // TOWER_H