#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QVector>
#include <QTimer>

#include "tower.h"
#include "monster.h"
#include "pausemenu.h"

class Map : public QGraphicsView
{
    Q_OBJECT
public:
     Map(QGraphicsView *parent = nullptr,QVector<QPointF> path={{0,0}},int towerNumber=0,QPoint towerPositions[]=nullptr);
     void createTower(int index);
     void showPlace(int index);
     void mapUpdate();
     void gameOver();
     void settingUpScene();
     void settingUpPath();
     void attackMonster(Monster *);
     QTimer *timer;
     QTimer *timerSpawn;

private slots:
     void mousePressEvent(QMouseEvent *event) override;
     void mouseMoveEvent(QMouseEvent *event) override;
     void keyPressEvent(QKeyEvent *event) override;
     void moveMonster();
     void spawnMonster();
     void pauseMenu();

private :
     QGraphicsSimpleTextItem * textHealth;
     QGraphicsSimpleTextItem * textMoney;
     QGraphicsRectItem *showedPlace;
     QGraphicsRectItem * pausePlacement;
     QVector<QPointF> path;
     QVector<Monster*> vectMonster;
     QGraphicsScene *scene;
     QPoint *towerPositions;
     QGraphicsRectItem *towerPlacement;
     Tower *t;
     int money=500;
     int health=20;
     int towerNumber;
signals:
   void pauseFunction();
   void gameEnd();
};

#endif // MAP_H
