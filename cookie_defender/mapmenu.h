#ifndef MAPMENU_H
#define MAPMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QLabel>

/**
* Description of the class
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
* @version	Number of the version
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
