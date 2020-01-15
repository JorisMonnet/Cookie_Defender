#include "tower.h"
#include "math.h"
#include "projectile.h"
#include <QDebug>
#include <QDir>


Tower::Tower(QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent)
{
    set(1);
    showedRange= new QGraphicsEllipseItem();
}

int Tower::howManyFiles(QString fold)
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

void Tower::set(int level)
{    
    maxLevel=howManyFiles(QString(":/icones/tower/%1").arg(type));
    int x=level-1;
    this->level=level;
    int costVar=0;
    int costToVar=100;
    int rangeVar=0;
    int speedVar=0;
    int damageVar=0;
    int proIndexVar=0;
    bool shieldVar=false;
    QString stringVar="";

    QFile file(":/icones/tower/data.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString lineRead;
        QTextStream flow(&file);
        for(int i=0;i<type;i++){
            lineRead=flow.readLine();
            countSearchCarac=0;
            stringVar.clear();
            for(int j =countSearchCarac;lineRead.at(j)!=';';j++){
                stringVar.append(lineRead.at(j));
                countSearchCarac++;
            }
            countSearchCarac++;
            costVar=searchCaracMonster(lineRead);
            costToVar=searchCaracMonster(lineRead);
            rangeVar=searchCaracMonster(lineRead);
            speedVar=searchCaracMonster(lineRead);
            damageVar=searchCaracMonster(lineRead);
            shieldVar=(searchCaracMonster(lineRead));
            proIndexVar=searchCaracMonster(lineRead);
        }
        file.close();
    }

    cost=costVar+x*50;
    costToPlace=costToVar;
    range=rangeVar+x*35;
    speed=speedVar+x;
    damage=damageVar+x*5;
    name=stringVar;
    shield=shieldVar;
    projIndex=proIndexVar;
    setPixmap(QPixmap(QString(":/icones/tower/%1/%2.png").arg(type).arg(x+1)).scaled(size,size));
}

int Tower::searchCaracMonster(QString lineRead)
{
   QString string;
   for(int j=countSearchCarac;lineRead.at(j)!=';';j++){
       string.append(lineRead.at(j));
       countSearchCarac++;
    }
    countSearchCarac++;
    return string.toInt();
}


void Tower::shotTower(Monster *target)
{
    shield?target->hp-=damage:target->hp-=damage*(1-target->shield/100);
}

bool Tower::hasTarget(Monster *target)
{
    //taking the center of the monster..
    double xM = target->x() + target->size/2;
    double yM = target->y() + target->size/2;
    double distance = sqrt(pow((xM-(this->x()+size/2)),2)+ pow((yM-(this->y()+size/2)),2));
    return distance<=range;
}

QLineF Tower::getAimLine(Monster *target)
{
    return QLineF(this->x(), this->y(), target->x(), target->y());
}

void Tower::showRange(QGraphicsScene*scene,bool isFilled)
{
    if(!scene->items().contains(showedRange)){
        showedRange->setRect(pos().rx()-range+size/2, pos().ry()-range+size/2, range*2, range*2);
        showedRange->setPen(QPen(Qt::black,3));
        if(isFilled)
            showedRange->setBrush(QBrush(QColor(0,0,0,128)));
        scene->addItem(showedRange);
        isShowingRange = true;
    }
}

void Tower::hideRange(QGraphicsScene*scene)
{
    scene->removeItem(showedRange);
    isShowingRange = false;
}

bool Tower::isPlaced(QGraphicsScene*scene)
{
    return scene->items().contains(this);
}

