#include "encyclowidg.h"
#include <QLabel>
#include <QDir>
#include <QFileInfo>
#include "tower.h"
#include "monster.h"

#include <QDebug>

EncycloWidg::EncycloWidg(QWidget *parent) : QWidget(parent)
{
   setupUi(this);
   labelTitleEncyclo->setFont(QFont("Brush Script MT",25));
   labelTowerLvl->setFont(QFont("Brush Script MT",20));

   number_tower=howManyFiles("../encyclo/pix/monster");
   number_monster=howManyFiles("../encyclo/pix/monster");

   qDebug()<<"number tow : "<<number_tower<<endl;
   qDebug()<<"number monst : "<<number_monster<<endl;

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

int EncycloWidg::howManyFiles(QString fold)
{
    QDir dir = fold;
    QFileInfoList listFold = dir.entryInfoList(QDir::Dirs | QDir::Files);
    int numberFiles = 0;

        for (int i = 0; i < listFold.size(); ++i) {
            QFileInfo fileInfos = listFold.at(i);
            if(fileInfos.isFile())
                numberFiles++;
        }
     return numberFiles;
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
