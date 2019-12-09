#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QPoint>
#include <QMouseEvent>
#include <QVector>
#include "tower.h"
#include "monster.h"

class Map : public QGraphicsView
{
    Q_OBJECT
public:
     Map(QGraphicsView *parent = nullptr);
     void createTower(int index);
     void showRange(int index);
     void showPlace(int index);
     void mapUpdate();
     void gameOver();
     void settingUpScene();
     void settingUpPath();

protected slots:
     void mousePressEvent(QMouseEvent *event) override;
     void mouseMoveEvent(QMouseEvent *event) override;
     void keyPressEvent(QKeyEvent *event) override;
     void moveMonster();
     void attackMonster(Monster * );
     void spawnMonster();

private :
     QGraphicsSimpleTextItem * textHealth;
     QGraphicsSimpleTextItem * textMoney;
     QGraphicsEllipseItem *showedRange;
     QGraphicsRectItem *showedPlace;
     QGraphicsPixmapItem * pause;

     QList<QPointF> path;
     QTimer *timer;
     QVector<Monster*> vectMonster;

     QGraphicsScene *scene;

     QPoint towerPositions[4]={{50,350},{500,350},{300,550},{700,550}};
     QGraphicsRectItem towerPlacement[4];
     bool towerCreated[4];
     Tower t[4];

     int money=400;
     int health=20;
};

#endif // MAP_H
