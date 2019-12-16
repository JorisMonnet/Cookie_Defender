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
     Map(QGraphicsView *parent = nullptr);
     void createTower(int index);
     void showPlace(int index);
     void mapUpdate();
     void gameOver();
     void settingUpScene();
     void settingUpPath();
     void attackMonster(Monster *);
     QTimer *timer;
     QTimer *timerSpawn;
     QTimer *timerWave;

private slots:
     void mousePressEvent(QMouseEvent *event) override;
     void mouseMoveEvent(QMouseEvent *event) override;
     void keyPressEvent(QKeyEvent *event) override;
     void moveMonster();
     void spawnMonster();
     void pauseMenu();
     void waveMonster();

private :
     QGraphicsSimpleTextItem * textHealth;
     QGraphicsSimpleTextItem * textMoney;
     QGraphicsRectItem *showedPlace;
     QGraphicsRectItem * pausePlacement;
     QVector<QPointF> path;
     QVector<Monster*> vectMonster;
     QGraphicsScene *scene;
     QPoint towerPositions[4]={{50,350},{500,350},{300,550},{700,550}};
     QGraphicsRectItem towerPlacement[4];
     Tower t[4];
     int money=500;
     int health=200;
signals:
   void pauseFunction();
   void gameEnd();
};

#endif // MAP_H
