#ifndef BULLET_H
#define BULLET_H

#include <qmath.h>
#include <QTimer>

#include "tower.h"

/**
* Description of the class
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
* @version	Number of the version
*/

class Projectile : public QObject, public QGraphicsPixmapItem
{
public:
    Projectile(Tower *t, QGraphicsScene *scene=nullptr,Monster *monsterTargetedSource=nullptr);
    const int velocity = 4;
    Monster *target;
    Tower *t;
    QGraphicsScene *scene;
public slots :
    void move(void);
};

#endif // BULLET_H
