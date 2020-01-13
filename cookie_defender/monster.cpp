#include "monster.h"
#include "math.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Monster::Monster(char x) : QGraphicsPixmapItem()
{
    int nameFileCount=x-'A';
    QString nameFromFile="";
    int hpCoef=1;
    int rewardCoef=1;
    int velocityCoef=1;
    int damageCoef=1;
    int shieldCoef=1;
    setPixmap(QPixmap(QString("../icones/monster/pix/%1.png").arg(x-65)).scaled(size,size));

    QFile file("../icones/monster/data.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString lineRead;
        QTextStream flow(&file);
        for(int i=0;i<nameFileCount+1;i++){
            lineRead=flow.readLine();
            countSearchCarac=0;
            nameFromFile.clear();

            for(int j =countSearchCarac;lineRead.at(j)!=';';j++){
                nameFromFile.append(lineRead.at(j));
                countSearchCarac++;
            }
            countSearchCarac++;

            hpCoef=searchCaracMonster(lineRead);
            rewardCoef=searchCaracMonster(lineRead);
            velocityCoef=searchCaracMonster(lineRead);
            damageCoef=searchCaracMonster(lineRead);
            shieldCoef=searchCaracMonster(lineRead);
        }
        file.close();
    }
    else{
        //Catching error
        qDebug()<<"Can't find file"<<endl;
    }
    name=nameFromFile;
    hp*=hpCoef;
    reward*=rewardCoef;
    velocity/=velocityCoef;
    damage*=damageCoef;
    shield*=shieldCoef;
}

int Monster::searchCaracMonster(QString lineRead)
{
   QString string;
   for(int j=countSearchCarac;lineRead.at(j)!=';';j++){
       string.append(lineRead.at(j));
       countSearchCarac++;
    }
    countSearchCarac++;
    return string.toInt();
}

void Monster::move(QVector<QPointF>path,int *health)
{
    for(int i=0;i<=velocity;i++){
        if(pos()==path.last()){
            setPos(path.first().toPoint());
            pathIndex=0;
            *health-=damage;
            return;
        }
        if(x() < path.at(pathIndex).x())
            setX(x()+1);
        else if(x() > path.at(pathIndex).x())
            setX(x()-1);
        if(y() < path.at(pathIndex).y())
            setY(y()+1);
        else if(y() > path.at(pathIndex).y())
            setY(y()-1);
        if(pos() == path.at(pathIndex).toPoint())
            pathIndex++;
    }
}

double Monster::toCookie(QVector<QPointF> path)
{
    return sqrt(pow(path.last().x()-this->x(),2)+pow(path.last().y()-this->y(),2));
}
