#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include "tower.h"

class Projectile : public QObject, public QGraphicsPixmapItem
{
public:
    Projectile(Tower *t, QGraphicsScene *scene=nullptr,Monster *monsterTargetedSource=nullptr);
    const int velocity = 5;
    QTimer *timer;
    QLineF line;
    Monster *target;
    Tower *t;
    QGraphicsScene *scene;
public slots :
    void move();
};

#endif // BULLET_H
