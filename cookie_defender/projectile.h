#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>

class Projectile : public QGraphicsPixmapItem
{
public:
    Projectile(int towerType=1);
    void move(QPointF);
    const int VELOCITY = 9;
};

#endif // BULLET_H
