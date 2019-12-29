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
     QGraphicsScene *scene;
     Map(QGraphicsView *parent = nullptr, QVector<QPointF> path={{0,0}},
         int towerNumber=0, QPoint towerPositions[]=nullptr, int money=500, QGraphicsPixmapItem *background=nullptr);
     void createTower(int index);
     void showPlace(int index);
     void mapUpdate();
     void gameOver();
     void settingUpScene();
     void settingUpPath();
     void attackMonster(Monster *);
     QTimer *timer;
     QTimer *timerSpawn;
     QVector<QPointF> path;
     int money;
     QPoint *towerPositions;
     QGraphicsPixmapItem *background;
     int towerNumber;
     Tower *towerClicked;
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
     QVector<Monster*> vectMonster;
     QGraphicsRectItem *towerPlacement;
     Tower *t;
     int health=20;
signals:
   void pauseFunction();
   void gameEnd();
   void clickedTower();
};

#endif // MAP_H
