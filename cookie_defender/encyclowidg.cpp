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
//******
   number_tower=howManyFiles("../encyclo/pix/tower");
   number_monster=howManyFiles("../encyclo/pix/monster");

   set();
}

void EncycloWidg::set()
{
    testBool=true;
    QString string = getSpecs(indexTower);
    QPixmap pix = getPix(indexTower);
    labelTowerPix->setPixmap(pix);
    //repeat for monster
    testBool=false;
    string.clear();
    string = getSpecs(indexMonster);
    QPixmap pix2 = getPix(indexMonster);
    labelMonsterPix->setPixmap(pix2);
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

QPixmap EncycloWidg::getPix(int index)
{

    QPixmap pix;
    if(testBool)
        pix=QPixmap(QString("../encyclo/pix/tower/%1").arg(index%number_tower));
    else
        pix=QPixmap(QString("../encyclo/pix/monster/%1").arg(index%number_monster));

    return pix;
}

QString EncycloWidg::getSpecs(int index)
{
    QString string;

    return string;
}

void EncycloWidg:: on_btnTower_clicked()
{
    indexTower++;
    set();
}

void EncycloWidg:: on_btnMonster_clicked()
{
    indexMonster++;
    set();
}
