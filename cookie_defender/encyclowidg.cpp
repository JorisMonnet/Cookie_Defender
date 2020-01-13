#include "encyclowidg.h"
#include <QLabel>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include "tower.h"
#include "monster.h"

#include <QDebug>

EncycloWidg::EncycloWidg(QWidget *parent) : QWidget(parent)
{
   setupUi(this);
   number_tower=howManyFiles("../icones/tower/pix");
   number_monster=howManyFiles("../icones/monster/pix");

   set();
}

void EncycloWidg::set()
{
    testBool=true;
    setSpecs();
    QPixmap pix = getPix().scaled(200,200,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    labelTowerPix->setPixmap(pix);
    //repeat for monster
    testBool=false;
    setSpecs();
    QPixmap pix2 = getPix().scaled(200,200,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    labelMonsterPix->setPixmap(pix2);

    labelTitleEncyclo->setFont(QFont("Brush Script MT",25));
    labelTowerLvl->setFont(QFont("Brush Script MT",20));

    labelMonsterText->setFont(QFont("Brush Script MT",18));
    labelTowerText->setFont(QFont("Brush Script MT",18));

    labelMonsterCaracHp->setFont(QFont("Brush Script MT",14));
    labelMonsterCaracShield->setFont(QFont("Brush Script MT",14));
    labelMonsterCaracDamage->setFont(QFont("Brush Script MT",14));
    labelMonsterCaracSpeed->setFont(QFont("Brush Script MT",14));
    labelMonsterCaracReward->setFont(QFont("Brush Script MT",14));
    labelMonsterCaracShield->setFont(QFont("Brush Script MT",14));

    labelTowerCaracCost->setFont(QFont("Brush Script MT",14));
    labelTowerCaracRange->setFont(QFont("Brush Script MT",14));
    labelTowerCaracDamage->setFont(QFont("Brush Script MT",14));
    labelTowerCaracFireRate->setFont(QFont("Brush Script MT",14));
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

QPixmap EncycloWidg::getPix()
{

    QPixmap pix;
    if(testBool)
        pix=QPixmap(QString("../icones/tower/pix/%1").arg(indexTower%number_tower));
    else
        pix=QPixmap(QString("../icones/monster/pix/%1").arg(indexMonster%number_monster));

    return pix;
}

void EncycloWidg::setSpecs()
{
    QString x;

    if(!testBool){
        QChar x(65+indexMonster%number_monster);
        Monster* monster=new Monster(x.toLatin1());

        labelMonsterCaracHp->setText(QString("HP : %1").arg(monster->hp));
        labelMonsterCaracShield->setText(QString("Shield : %1").arg(monster->shield));
        labelMonsterCaracDamage->setText(QString("Damage : %1").arg(monster->damage));
        labelMonsterCaracSpeed->setText(QString("Speed : %1").arg(monster->velocity));
        labelMonsterCaracReward->setText(QString("Reward : %1").arg(monster->reward));
        labelMonsterText->setText(monster->name);
        delete monster;
    }
    else{
        Tower *tower=new Tower();
        tower->type=indexTower%number_tower+1;
        tower->set(1);

        labelTowerCaracCost->setText(QString("Cost : %1").arg(tower->cost));
        labelTowerCaracRange->setText(QString("Range : %1").arg(tower->range));
        labelTowerCaracDamage->setText(QString("Damage : %1").arg(tower->damage));
        labelTowerCaracFireRate->setText(QString("FireRate : %1").arg(tower->speed));
        labelTowerText->setText(tower->name);
        delete tower;
    }
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
