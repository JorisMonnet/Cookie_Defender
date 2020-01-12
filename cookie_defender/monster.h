#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>
#include <QProgressBar>

class Monster : public QGraphicsPixmapItem
{
public:
    Monster(char);
    const int size=40;
    int hp=20;
    int shield=25;
    int reward=25;
    int velocity=2;
    int damage=2;
    int pathIndex=0;
    QString name="Walker";
    void move(QVector<QPointF>path,int *health);
    double toCookie(QVector<QPointF>path);
    QProgressBar *lifeBar;
};

#endif // MONSTER_H
