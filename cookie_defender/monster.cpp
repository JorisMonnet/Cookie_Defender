#include "monster.h"

Monster::Monster(char charX) : QGraphicsPixmapItem()
{
    int nameFileCount=charX-'A';
    QString nameFromFile="";
    double hpCoef=1;
    double rewardCoef=1;
    double velocityCoef=1;
    double damageCoef=1;
    double shieldCoef=1;

    setPixmap(QPixmap(QString(":/icones/monster/pix/%1.png").arg(charX-65)).scaled(size,size));

    QFile file(":/icones/monster/data.txt");
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
    }
    name=nameFromFile;
    hp*=hpCoef;
    reward*=int(rewardCoef);
    velocity*=velocityCoef;
    damage*=damageCoef;
    shield*=shieldCoef;

    stackHp=hp;
    rectRed=new QGraphicsRectItem(QRectF(x()+5,y()-9,40,10));
    rectGreen=new QGraphicsRectItem(QRectF(x()+5,y()-9,40,10));
    rectRed->setBrush(Qt::red);
    rectGreen->setBrush(Qt::green);
    rectGreen->setZValue(1);
    rectRed->setZValue(0);
}

void Monster::updateMonster(void)
{
    rectGreen->setRect(x()+5,y()-9,(40-((stackHp-hp)/stackHp)*40),10);
    rectRed->setRect(x()+5,y()-9,40,10);
}

double Monster::searchCaracMonster(QString lineRead)
{
   QString string;
   for(int j=countSearchCarac;lineRead.at(j)!=';';j++){
       string.append(lineRead.at(j));
       countSearchCarac++;
    }
    countSearchCarac++;
    return string.toDouble();
}


bool Monster::move(QVector<QPointF>path,double *health)
{
    for(int i=0;i<=velocity;i++){
        if(pos()==path.last()){
            setPos(path.first().toPoint());
            pathIndex=0;
            *health-=damage;
            return true;
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
        updateMonster();
    }
    return false;
}

double Monster::toCookie(QVector<QPointF> path)
{
    double total=0;
    for(int j=path.indexOf(path.last());j>pathIndex+1;j--)
        total+=sqrt(pow(path.at(j-1).x()-path.at(j).x(),2)+pow(path.at(j-1).y()-path.at(j).y(),2));
    return total;
}
