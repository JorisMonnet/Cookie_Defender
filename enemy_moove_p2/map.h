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
     QTimer *timer;
     QTimer *timerSpawn;
     QTimer *timerTower;
     QTimer *timerWave;
     QVector<QPointF> path;
     QPoint *towerPositions;
     QGraphicsPixmapItem *background;
     int money;
     int towerNumber;
     void gameOver();
private slots:
     void mousePressEvent(QMouseEvent *event) override;
     void mouseMoveEvent(QMouseEvent *event) override;
     void keyPressEvent(QKeyEvent *event) override;
     void moveMonster();
     void spawnMonster();
     void pauseMenu();
     void shotTower();
     void waveMonster();

private :
     QGraphicsPixmapItem * sell;
     QGraphicsPixmapItem * upgrade;
     QGraphicsPixmapItem *towerImage;
     QGraphicsPixmapItem * pauseIcon;
     QGraphicsSimpleTextItem * textHealth;
     QGraphicsSimpleTextItem * textMoney;
     QGraphicsRectItem *showedPlace;
     QGraphicsRectItem *clickableItem;
     QVector<Monster*> vectMonster;
     QGraphicsRectItem *towerPlacement;
     Tower *t;
     int indexTower=0;
     int health=20;
     void createClickableItem(double x,double y,int width,int height);
     void createTower(int index);
     void showPlace(int index);
     void mapUpdate();
     void settingUpScene();
     void attackMonster(Monster *);
signals:
   void pauseFunction();
   void gameEnd();
};

#endif // MAP_H
