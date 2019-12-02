#include "map.h"

//#include "monster.h"

Map::Map(QGraphicsView* parent) : QGraphicsView(parent)
{

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,1000);
    scene= new QGraphicsScene(this);
    setScene(scene);
    t[2].set(2);
    QGraphicsRectItem *topMap = new QGraphicsRectItem(0,0,this->width(),450);
    QGraphicsRectItem *bottomMap = new QGraphicsRectItem(0,550,this->width(),450);
    QGraphicsPixmapItem *finish = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *finish2 = new QGraphicsPixmapItem();

    finish->setPos(950,450);
    finish->setPixmap(QPixmap("Cookie.png").scaled(50,50));
    finish2->setPos(950,500);
    finish2->setPixmap(QPixmap("Cookie.png").scaled(50,50));
    topMap->setBrush(QBrush(Qt::green));
    topMap->setPen(QPen(Qt::green));
    bottomMap->setBrush(QBrush(Qt::green));
    bottomMap->setPen(QPen(Qt::green));
    scene->addItem(topMap);
    scene->addItem(bottomMap);
    scene->addItem(finish);
    scene->addItem(finish2);
    QGraphicsTextItem *textHealth = new QGraphicsTextItem(QString("Health: ")+QString::number(health));
    textHealth->setScale(1.5);
    textHealth->setPos(0,0);
    scene->addItem(textHealth);
    QGraphicsTextItem *textMoney = new QGraphicsTextItem(QString("Money: ")+QString::number(money));
    textMoney->setScale(1.5);
    textMoney->setPos(0,50);
    scene->addItem(textMoney);
    for(int i=0;i<4;i++)
    {
        towerPlacement[i].setRect(towerPositions[i].rx(),towerPositions[i].ry(),100,100);
        towerPlacement[i].setBrush(QBrush(Qt::red));
        towerPlacement[i].setPen(QPen(Qt::red));
        scene->addItem(&towerPlacement[i]);
    }

    for(int i=0;i<this->height();i+=50)
        scene->addLine(0,i,this->width(),i);
    for(int i=0;i<this->width();i+=50)
        scene->addLine(i,0,i,this->height());
}
void Map::mousePressEvent(QMouseEvent *event)
{
    bool statement=false;
    for(int i=0;i<4;i++){
        if(towerPlacement[i].contains(mapToScene(event->pos()))){
            statement=true;
            if(!(towerCreated[i])){
                createTower(i);
            }
            else{
                showRange(i);
            }
        }
    }
    if(!statement){
        scene->removeItem(&showedRange);
    }
}
void Map::createTower(int index)
{
    if (money>=100){
        t[index].setPos(towerPositions[index]);
        scene->addItem(&t[index]);
        money-=100;
        towerCreated[index]=true;
    }
}
void Map::showRange(int i)
{
    showedRange.setRect(towerPositions[i].rx()-(t[i].range/2-50),towerPositions[i].ry()-(t[i].range/2-50),t[i].range,t[i].range);
    showedRange.setPen(QPen(Qt::black,0));
    showedRange.setBrush(QBrush(QColor(0,0,0,128)));
    scene->addItem(&showedRange);
}
