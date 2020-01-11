#include "encyclowidg.h"
#include <QLabel>
#include "tower.h"
#include "monster.h"

EncycloWidg::EncycloWidg(QWidget *parent) : QWidget(parent)
{
   setupUi(this);
   labelTitleEncyclo->setFont(QFont("Brush Script MT",25));
   labelTowerLvl->setFont(QFont("Brush Script MT",20));
   QString string = getSpecs(index);
   QPixmap pix = getPix(index);
}

QPixmap EncycloWidg::getPix(int index)
{
    QPixmap pix;

    return pix;
}

QString EncycloWidg::getSpecs(int index)
{
    QString string;

    return string;
}

void EncycloWidg:: on_btnTower_clicked()
{

}

void EncycloWidg:: on_btnMonster_clicked()
{

}
