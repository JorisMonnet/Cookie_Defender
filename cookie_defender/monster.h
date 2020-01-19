#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QFile>
#include <QTextStream>
#include <QBrush>

#include "math.h"

/**
* Class of the ennemies on the map
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
*/

class Monster : public QGraphicsPixmapItem
{
public:
    Monster(char);
    const int size=40;
    int reward=25;
    double velocity=2;
    double hp=20;
    double shield=25;
    double damage=0;
    QString name;
    QGraphicsRectItem *rectRed,*rectGreen;
    double toCookie(QVector<QPointF>);
    bool move(QVector<QPointF>,double*);
private:
    int countSearchCarac;
    int pathIndex=0;
    double stackHp=0;
    double searchCaracMonster(QString);
    void updateMonster(void);
};

#endif // MONSTER_H
