#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>

class Projectile : public QGraphicsPixmapItem
{
public:
    Projectile(QPoint pos, int towerType=1);
    void move(int dx, int dy, QPoint point);
    const int VELOCITY = 3;
    QPoint pos;
};

#endif // BULLET_H
