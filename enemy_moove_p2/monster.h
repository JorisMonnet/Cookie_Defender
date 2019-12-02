/**
* Creeps class :
* -move
* -attack
* -set the basics parameters
*
* @author	Adrien Paysant
* @version	1.0
*/

#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QRect>

class Monster : public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Monster();

    int hp=100;
    int shield=25;

    const float velocity=1;
    const int dammage=25;
};

#endif // MONSTER_H


