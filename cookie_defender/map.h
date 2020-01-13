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
#include <QDebug>
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
    void moveMonster();
    void pauseMenu();
    void towerDetect();
    void aliveMonster();
    void spawnMonster();
private :
    static const int iconNumber=5;
    QGraphicsPixmapItem * listIcon[iconNumber];
    QGraphicsPixmapItem * background;
    QGraphicsSimpleTextItem * textHealth;
    QGraphicsSimpleTextItem * textMoney;
    QGraphicsRectItem * clickableItem;
    QVector<Monster*> vectMonster;
    QGraphicsRectItem * towerPlacement;
    QVector<QPointF> path;
    QPoint *towerPositions;
    Tower *t;

    int indexTower=0;
    double health;
    const double stackHealth=20;
    int towerNumber;
    int width;
    int height;
    int infiniteSpawn=1;
    bool hasBeen=true;
    int waveIndex=1;
    bool statement=true;
    bool hasWave=false;
    QString waveCode;
    const int iconSize = 50;
    void createClickableItem(double x,double y,int size);
    void createTower(int index,int type);
    void mapUpdate();
    void attackMonster(Monster *);
    void hideUpgradeSell();
    QPointF findPos(int indexTower);
    bool isEmpty(QPointF point);
    void addMonster(char c);
    void addIcon(int indexListIcon);
    int howManyFiles(QString fold);
    int numberOfMonster=0;
    int *waveTab;
    QGraphicsRectItem *rectRed;
    QGraphicsRectItem *rectGreen;
signals:
   void pauseFunction();
   void gameEnd();
};

#endif // MAP_H
