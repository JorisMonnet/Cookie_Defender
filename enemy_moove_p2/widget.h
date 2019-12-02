#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H

#ifndef MONSTERCHILD_H
#define MONSTERCHILD_H

#include <QWidget>

class Monster : public QWidget
{

public:
    Monster(QWidget *parent=nullptr);

    float velocity;
    int pv;
    int dammage;
    int shield;
    QPointF pos;

protected :
    void moove(void);
    void attack(void);
    void tp(void);


};
#endif // MONSTERCHILD_H
