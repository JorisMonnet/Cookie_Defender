#include "encyclowidg.h"
#include <QLabel>
#include "tower.h"
#include "monster.h"

EncycloWidg::EncycloWidg(QWidget *parent) : QWidget(parent)
{
   setupUi(this);
   labelTitleEncyclo->setFont(QFont("Brush Script MT",25));
   labelTowerLvl->setFont(QFont("Brush Script MT",20));

   testBool=true;
   QString string = getSpecs(indexTower,testBool);
   QPixmap pix = getPix(indexTower,testBool);
   //set pix & carac
   //repeat for monster
   testBool=false;
   string.clear();
   string = getSpecs(indexTower,testBool);
   pix = getPix(indexTower,testBool);
}

QPixmap EncycloWidg::getPix(int index,bool testBool)
{
    QPixmap pix;

    return pix;
}

QString EncycloWidg::getSpecs(int index,bool testBool)
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
