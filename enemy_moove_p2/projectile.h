#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>

class Projectile : public QGraphicsPixmapItem
{
public:
    Projectile(QGraphicsPixmapItem*parent=nullptr, QLine * path=nullptr,int towerType=1);
    const int velocity = 3;
};

#endif // BULLET_H
