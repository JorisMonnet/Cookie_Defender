#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsScene>
#include <QMouseEvent>
#include "tower.h"

#include "monster.h"

class Map : public QGraphicsView
{
    Q_OBJECT
public:
     Map(QWidget *parent = nullptr);

     void createTower(int index);
     void showRange(int index);

     QTimer * timer = nullptr;
     QList<QPointF> points;

     Monster* tabMonster[5];

protected slots:
    void mousePressEvent(QMouseEvent *event) override;

public slots:
     void move_monster();
     void attack_monster();
     void tp_monster();
     void settingUpScene();
private :
     QPoint start={0,500};
     QGraphicsScene *scene;
     QPoint towerPositions[4]={{50,350},{500,350},{300,550},{700,550}};
     bool towerCreated[4];
     QGraphicsEllipseItem showedRange;
     QGraphicsRectItem towerPlacement[4];
     int money=400;
     int health=20;
     Tower t[4];
};

#endif // MAP_H
