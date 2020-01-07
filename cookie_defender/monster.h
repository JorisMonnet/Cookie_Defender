#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>

class Monster : public QGraphicsPixmapItem
{
public:
    Monster();
    const int size=40;
    int hp=20;
    int shield=25;
    int reward=25;
    const int velocity=2;
    const int dammage=1;
    int pathIndex=0;
    void move(QVector<QPointF>path);
    double toCookie(QVector<QPointF>path);
};

#endif // MONSTER_H


