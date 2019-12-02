#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QWidget>

#include "monster.h"

class Map : public QGraphicsView
{
    Q_OBJECT
public:
     Map(QWidget *parent = nullptr);

     QTimer * timer = nullptr;
     QList<QPointF> points;

     Monster* tabMonster[5];
     
public slots:
     void move_monster();
     void attack_monster();
     void tp_monster();
};

#endif // MAP_H
