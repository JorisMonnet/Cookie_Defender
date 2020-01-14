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
    QLineF getAimLine(Monster *target);
    int searchCaracMonster(QString lineRead);
    int howManyFiles(QString fold);
    bool shield;
    int projIndex;
    int countSearchCarac=0;
    QString name;
    int damage;
    int range;
    int costToPlace;
    int cost;
    int speed;
    int level;
    int type=1;   //type 1 = classsic tower type 2 = mageTower
    const int size=100;
    int maxLevel;
    bool isShowingRange=false;
    QGraphicsEllipseItem *showedRange=nullptr;

};

#endif // TOWER_H
