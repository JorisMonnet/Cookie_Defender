#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "monster.h"

class Tower : public QGraphicsPixmapItem
{
public:
    Tower(QGraphicsPixmapItem *parent=nullptr);
    void showRange(QGraphicsScene *scene);
    void hideRange(QGraphicsScene *scene);
    bool hasInRange(Monster *monster);
    void shot(Monster *monster);
    void set(int level);
    bool isPlaced(QGraphicsScene *scene);
    //void attack(MonsterChild *monster);

    int damage;
    int range;
    int cost=100;
    int shotSpeed;
    int level;
    const int towerSize=100;
    bool isShowingRange=false;
    QGraphicsEllipseItem *showedRange=nullptr;
    QTimer *fireTimer = nullptr;
};
