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
    int shieldCoef=1;
    setPixmap(QPixmap(QString("../icones/monster/pix/%1.png").arg(x-65)).scaled(size,size));

    QFile file("../icones/monster/data.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString lineRead;
        QTextStream flow(&file);
        for(int i=0;i<nameFileCount+1;i++){
            lineRead=flow.readLine();
            int k=0;
            string.clear();
            nameFromFile.clear();

            for(int j =k;lineRead.at(j)!=';';j++){
                nameFromFile.append(lineRead.at(j));
                k++;
            }

            for(int j=k+1;lineRead.at(j)!=';';j++){
                string.append(lineRead.at(j));
                k++;
            }
            hpCoef=string.toInt();
            string.clear();
            for(int j=k+2;lineRead.at(j)!=';';j++){
                string.append(lineRead.at(j));
                k++;
            }
            rewardCoef=string.toInt();
            string.clear();
            for(int j=k+1;lineRead.at(j)!=';';j++){
                string.append(lineRead.at(j));
                k++;
            }
            velocityCoef=string.toInt();
            string.clear();
            for(int j=k+2;lineRead.at(j)!=';';j++){
                string.append(lineRead.at(j));
                k++;
            }
            damageCoef=string.toInt();
            string.clear();
            for(int j=k+5;lineRead.at(j)!=';';j++){
                string.append(lineRead.at(j));
            }
            shieldCoef=string.toInt();
        }
        name=nameFromFile;
        hp*=hpCoef;
        reward*=rewardCoef;
        velocity/=velocityCoef;
        damage*=damageCoef;
        shield*=shieldCoef;

        file.close();
    }
    else{
        //Catching error
        qDebug()<<"Can't find file"<<endl;
    }
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
