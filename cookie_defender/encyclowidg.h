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
     int indexMonster=0;
     int indexTower=0;
     bool testBool;
     const int number_monster=2;
     const int number_tower=2;

public slots:
private slots :
    void  on_btnTower_clicked();
    void  on_btnMonster_clicked();
};

#endif // ENCYCLOWIDG_H
