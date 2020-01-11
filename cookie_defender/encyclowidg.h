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
     QString getSpecs(int index,bool testBool);
     QPixmap getPix(int index,bool testBool);
     int howManyFiles(QString fold);
     int indexMonster=0;
     int indexTower=0;
     bool testBool;
     int number_monster;
     int number_tower;

public slots:
private slots :
    void  on_btnTower_clicked();
    void  on_btnMonster_clicked();
};

#endif // ENCYCLOWIDG_H
