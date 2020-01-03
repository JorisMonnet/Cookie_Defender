#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Tower : public QGraphicsPixmapItem
{
public:
    Tower(QGraphicsPixmapItem *parent=nullptr);
    void showRange(QGraphicsScene *scene,bool isFilled);
    void hideRange(QGraphicsScene *scene);
    void set(int level);
    bool isPlaced(QGraphicsScene *scene);
    int damage;
    int range;
    int cost=100;
    int speed;
    int level;
    const int towerSize=100;
    const int maxLevel = 3;
    bool isShowingRange=false;
    QGraphicsEllipseItem *showedRange=nullptr;
};

#endif // TOWER_H
