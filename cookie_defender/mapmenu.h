#ifndef MAPMENU_H
#define MAPMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QLabel>

/**
* Menu where the player choose between the available maps
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
*/

class MapMenu : public QWidget
{
    Q_OBJECT
public:
    MapMenu(QWidget *parent=nullptr);
    QPushButton *exit,*map1,*map2;

signals:
    void exitMapMenu(void);
    void mapChosen(int);
};

#endif // MAPMENU_H
