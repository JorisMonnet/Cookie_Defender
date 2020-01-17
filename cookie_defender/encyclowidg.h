#ifndef ENCYCLOWIDG_H
#define ENCYCLOWIDG_H

#include <QWidget>
#include "ui_formEncyclo.h"

/**
* Link between encyclopedia (the view) and the form
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
*/

class EncycloWidg : public QWidget, public Ui::formEncyclo
{
    Q_OBJECT
public:
     EncycloWidg(QWidget *parent = nullptr);
private :
     void setSpecs(void);
     QPixmap getPix(void);
     int howManyFiles(QString fold);
     void set(void);
     int indexMonster=0;
     int indexTower=0;
     bool testBool;
     int numberMonster;
     int numberTower;
private slots :
    void  on_btnTower_clicked(void);
    void  on_btnMonster_clicked(void);
};

#endif // ENCYCLOWIDG_H
