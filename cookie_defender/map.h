#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QVector>
#include <QTimer>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include "pausemenu.h"
#include "projectile.h"


class Map : public QGraphicsView
{
    Q_OBJECT
public:
    Map(QGraphicsView *parent = nullptr, QVector<QPointF> path={{0,0}},
        int towerNumber=0, QPoint towerPositions[]=nullptr, int money=500, QGraphicsPixmapItem *background=nullptr,
        int width=1000,int height=1000,int difficulty=1);
    ~Map()override;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *timerTower;
    QTimer *timerWave;
    QTimer *timerSpawn;

    int money;
    int remainingTimeSpawn=0;
    int remainingTimeWave=0;
    int difficulty;
    int countTimeInf = 1020;

public slots :
    void gameOver();
    void waveMonster();
    void gameWin();

private slots:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void moveMonster(void);
    void pauseMenu(void);
    void towerDetect(void);
    void aliveMonster(void);
    void spawnMonster(void);

private :

    void createClickableItem(double x,double y,int size);
    void createTower(int index,int type);
    void mapUpdate(void);
    void attackMonster(Monster *);
    void hideUpgradeSell(void);
    void addMonster(char c);
    void addIcon(int indexListIcon);
    QPointF findPos(int indexTower);
    bool isFree(QPointF point);
    int howManyFiles(QString fold);

    QGraphicsPixmapItem ** listIcon;
    QGraphicsPixmapItem * background;

    QGraphicsSimpleTextItem * textHealth,*textMoney;

    QGraphicsRectItem * clickableItem;
    QGraphicsRectItem * towerPlacement;
    QGraphicsRectItem *rectRed,*rectGreen;

    QVector<Monster*> vectMonster;
    QVector<QPointF> path;

    QPoint *towerPositions;
    Tower *t;

    int iconNumber;
    int indexTower=0;
    int towerNumber;
    int width;
    int height;
    int infiniteSpawn=1;
    int waveIndex=1;
    int numberOfMonster=0;
    int *waveTab;
    const int iconSize = 50;

    double health;
    const double stackHealth=20;

    bool hasWave=false;

    QString waveCode;

signals:
   void pauseFunction(void);
   void gameEnd(void);
   void moneySound(void);
   void gameWinSound(void);
   void enemyTPSound(void);
};

#endif // MAP_H
