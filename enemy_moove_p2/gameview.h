#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>
#include <QVBoxLayout>

#include "towermenu.h"
#include "map.h"

class GameView : public QWidget
{
    Q_OBJECT
public:
    GameView(QWidget*parent=nullptr,Map*map=nullptr);
    TowerMenu*towerMenu;
    Map*map;
private :
    QVBoxLayout *mainLay;
};

#endif // GAMEVIEW_H
