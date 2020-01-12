#include "monster.h"
#include "math.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Monster::Monster(char x) : QGraphicsPixmapItem()
{
    QString string;
    int nameFileCount=x-'A';
    QString nameFromFile="";
    int hpCoef=1;
    int rewardCoef=1;
    int velocityCoef=1;
    int damageCoef=1;

    QFile file("../icones/monster/data.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString lineRead;
        QTextStream flow(&file);
        for(int i=0;i<nameFileCount+1;i++){
            lineRead=flow.readLine();
            qDebug()<<"line lue : "<<lineRead<<endl;
        }
        hp*=hpCoef;
        reward*=rewardCoef;
        velocity/=velocityCoef;
        damage*=damageCoef;
        file.close();
    }
    else{
        //Catching error
        qDebug()<<"Can't find file"<<endl;
    }
}

void Monster::move(QVector<QPointF>path)
{
    for(int i=0;i<=velocity;i++){
        if(pos()==path.last())
            return;
        if(x() < path.at(pathIndex).x())
            setX(x()+1);
        if(x() > path.at(pathIndex).x())
            setX(x()-1);
        if(y() < path.at(pathIndex).y())
            setY(y()+1);
        if(y() > path.at(pathIndex).y())
            setY(y()-1);
        if(pos() == path.at(pathIndex).toPoint())
            pathIndex++;
    }
    if(pos()==path.last()){
        setPos(path.first().toPoint());
        pathIndex=0;
    }
}

double Monster::toCookie(QVector<QPointF> path)
{
    return sqrt(pow(path.last().x()-this->x(),2)+pow(path.last().y()-this->y(),2));
}
