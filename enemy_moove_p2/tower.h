#ifndef TOWER_H
#define TOWER_H

#include <QImage>
#include <QGraphicsPixmapItem>

class Tower : public QGraphicsPixmapItem
{
public:
    Tower(QGraphicsPixmapItem *parent=nullptr);
    void set(int level);
    //void attack(MonsterChild *monster);
    int damage;
    int range;
    int cost=100;
    float speed;
    int level;
};

#endif // TOWER_H
