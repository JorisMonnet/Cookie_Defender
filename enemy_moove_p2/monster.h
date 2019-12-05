/**
* Creeps class :
* -move
* -attack
* -set the basics parameters
*
* @author	Adrien Paysant/Ugo Crucy/Joris Monnet
* @version	1.0
*/

#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>

class Monster : public QGraphicsPixmapItem
{
public:
    Monster();
    const int size=40;
    int hp=100;
    int shield=25;
    const float velocity=1;
    const int dammage=1;
};

#endif // MONSTER_H


