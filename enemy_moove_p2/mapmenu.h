#ifndef MAPMENU_H
#define MAPMENU_H

#include <QWidget>
#include <QPushButton>

class MapMenu : public QWidget
{
    Q_OBJECT
public:
    MapMenu(QWidget *parent=nullptr);
    QPushButton *exit;
    QPushButton *map1,*map2;
signals:
    void exitMapMenu();
    void mapChosen(int);
};

#endif // MAPMENU_H
