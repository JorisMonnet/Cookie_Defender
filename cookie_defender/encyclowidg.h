#ifndef ENCYCLOWIDG_H
#define ENCYCLOWIDG_H

#include <QWidget>
#include "ui_formEncyclo.h"

class EncycloWidg : public QWidget, public Ui::formEncyclo
{
    Q_OBJECT
public:
     EncycloWidg(QWidget *parent = nullptr);
private :
     void setSpecs();
     QPixmap getPix();
     int howManyFiles(QString fold);
     void set();
     int indexMonster=0;
     int indexTower=0;
     bool testBool;
     int numberMonster;
     int numberTower;
private slots :
    void  on_btnTower_clicked();
    void  on_btnMonster_clicked();
};

#endif // ENCYCLOWIDG_H
