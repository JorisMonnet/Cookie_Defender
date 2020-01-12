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
   number_tower=howManyFiles("../encyclo/pix/tower");
   number_monster=howManyFiles("../encyclo/pix/monster");

   set();
}

void EncycloWidg::set()
{
    testBool=true;
    QString string = getSpecs();
    QPixmap pix = getPix().scaled(200,200,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    labelTowerPix->setPixmap(pix);
    labelTowerCarac->setText(string);
    //repeat for monster
    testBool=false;
    string.clear();
    string = getSpecs();
    QPixmap pix2 = getPix().scaled(200,200,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    labelMonsterPix->setPixmap(pix2);
    labelMonsterCarac->setText(string);

    labelTitleEncyclo->setFont(QFont("Brush Script MT",25));
    labelTowerLvl->setFont(QFont("Brush Script MT",20));
    labelTowerText->setFont(QFont("Brush Script MT",14));
    labelMonsterText->setFont(QFont("Brush Script MT",14));
    labelTowerCarac->setFont(QFont("Brush Script MT",14));
    labelMonsterCarac->setFont(QFont("Brush Script MT",14));
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
        pix=QPixmap(QString("../encyclo/pix/tower/%1").arg(indexTower%number_tower));
    else
        pix=QPixmap(QString("../encyclo/pix/monster/%1").arg(indexMonster%number_monster));

    return pix;
}

QString EncycloWidg::getSpecs()
{
    QString string;
    QString x;

    if(!testBool){
        QChar x(65+indexMonster%number_monster);
        char xC=x.toLatin1();
        Monster* monster=new Monster(xC);
        string.append("HP : ");
        string.append(monster->hp);
        string.append("\n");
        string.append("Shield : ");
        string.append(monster->shield);
        string.append("\n");
        string.append("Speed : ");
        string.append(monster->velocity);
        string.append("\n");
        string.append("Damage : ");
        string.append(monster->damage);
        string.append("\n");
        string.append("Reward : ");
        string.append(monster->reward);
        string.append("\n");
        qDebug()<<string<<endl;
    }
    else{
        Tower *tower=new Tower();
        tower->type=indexTower%number_tower;
        tower->set(1);
        string.append("Cost : ");
        string.append(tower->cost);
        string.append("\n");
        string.append("Damage : ");
        string.append(tower->damage);
        string.append("\n");
        string.append("Range : ");
        string.append(tower->range);
        string.append("\n");
        string.append("FireRate : ");
        string.append(tower->speed);
        string.append("\n");
    }
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
