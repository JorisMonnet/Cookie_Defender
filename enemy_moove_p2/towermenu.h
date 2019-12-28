#ifndef TOWERMENU_H
#define TOWERMENU_H

#include <QGraphicsView>
#include "tower.h"

class TowerMenu : public QGraphicsView
{
public:
    TowerMenu(QGraphicsView*parent=nullptr);
    Tower *t;
};

#endif // TOWERMENU_H
