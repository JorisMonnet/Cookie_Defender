#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsScene>
#include <QDir>

#include "monster.h"

/**
* Class of the towers on the map
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
*/

class Tower : public QGraphicsPixmapItem
{
public:
    Tower(QGraphicsPixmapItem *parent=nullptr);
    const int size=100;
    int type=1;
    int costToPlace;
    int cost;
    int damage;
    int range;
    int speed;
    int level;
    int maxLevel;
    int projIndex;
    bool shield;
    bool isShowingRange=false;
    QString name;

    void set(int level);
    void shot(Monster*);
    void hideRange(QGraphicsScene*);
    void showRange(QGraphicsScene*,bool);
    bool isPlaced(QGraphicsScene*);
    bool hasTarget(Monster*);

private:
    QGraphicsEllipseItem *showedRange=nullptr;

    int searchCaracMonster(QString);
    int howManyFiles(QString);
    int countSearchCarac=0;
};

#endif // TOWER_H
