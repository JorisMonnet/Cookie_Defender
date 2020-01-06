#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QVector>
#include <QTimer>

#include "monster.h"
#include "pausemenu.h"

class Map : public QGraphicsView
{
    Q_OBJECT
public:
    Map(QGraphicsView *parent = nullptr, QVector<QPointF> path={{0,0}},
        int towerNumber=0, QPoint towerPositions[]=nullptr, int money=500, QGraphicsPixmapItem *background=nullptr);
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *timerSpawn;
    QTimer *timerTower;
    QTimer *timerWave;
    int money;
public slots :
    void gameOver();
private slots:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void moveMonster();
    void spawnMonster();
    void pauseMenu();
    void towerDetect();
    void waveMonster();
    void aliveMonster();
private :
    QGraphicsPixmapItem * sell;
    QGraphicsPixmapItem * upgrade;
    QGraphicsPixmapItem * classicTowerImage;
    QGraphicsPixmapItem * mageTowerImage;
    QGraphicsPixmapItem * pauseIcon;
    QGraphicsPixmapItem * background;
    QGraphicsSimpleTextItem * textHealth;
    QGraphicsSimpleTextItem * textMoney;
    QGraphicsRectItem * showedPlace;
    QGraphicsRectItem * clickableItem;
    QVector<Monster*> vectMonster;
    QGraphicsRectItem * towerPlacement;
    QVector<QPointF> path;
    QPoint * towerPositions;
    Tower * t;
    int indexTower=0;
    int health=20;
    int towerNumber;
    void createClickableItem(double x,double y,int width,int height);
    void createTower(int index,int type);
    void showPlace(int index);
    void mapUpdate();
    void settingUpScene();
    void attackMonster(Monster *);
    void hideUpgradeSell();
signals:
   void pauseFunction();
   void gameEnd();
};

#endif // MAP_H
