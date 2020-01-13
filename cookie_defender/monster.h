#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>
#include <QProgressBar>

class Monster : public QGraphicsPixmapItem
{
public:
    Monster(char);
    const int size=40;
    double hp=20;
    double shield=25;
    double reward=25;
    double velocity=2;
    double damage=2;
    int pathIndex=0;
    void move(QVector<QPointF>path,double *health);
    double toCookie(QVector<QPointF>path);
    QString name;

    QProgressBar *lifeBar;
private:
    double searchCaracMonster(QString lineRead);
    QString lineRead;
    int countSearchCarac;
};

#endif // MONSTER_H
