#ifndef ENCYCLOWIDG_H
#define ENCYCLOWIDG_H

#include <QWidget>
#include "ui_formEncyclo.h"

class EncycloWidg : public QWidget, public Ui::formEncyclo
{
    Q_OBJECT
public:
     EncycloWidg(QWidget *parent = nullptr);

public slots:
private slots :
    void  on_btnTower_clicked();
    void  on_btnMonster_clicked();
};

#endif // ENCYCLOWIDG_H
