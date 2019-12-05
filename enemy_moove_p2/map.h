#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QVector>
#include "tower.h"

#include "monster.h"

class Map : public QGraphicsView
{
    Q_OBJECT
public:
     Map(QWidget *parent = nullptr);

     void createTower(int index);
     void showRange(int index);
     void showPlace(int index);

     QList<QPointF> points;

     QVector<Monster*> vectMonster;

     //for test
     QGraphicsRectItem *rect;

protected slots:
     void mousePressEvent(QMouseEvent *event) override;
     void mouseMoveEvent(QMouseEvent *event) override;
     void moveMonster();
     void attackMonster();
     void settingUpScene();
private :
     QGraphicsTextItem * textHealth;
     QGraphicsTextItem * textMoney;
     QPoint start={0,480};
     QGraphicsScene *scene;
     QPoint towerPositions[4]={{50,350},{500,350},{300,550},{700,550}};
     bool towerCreated[4];
     QGraphicsEllipseItem showedRange;
     QGraphicsRectItem showedPlace;
     QGraphicsRectItem towerPlacement[4];
     int money=400;
     int health=20;
     Tower t[4];
};

#endif // MAP_H
