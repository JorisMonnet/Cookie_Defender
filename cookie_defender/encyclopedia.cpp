#include "encyclopedia.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "tower.h"
#include "monster.h"

Encyclopedia::Encyclopedia(QWidget *parent) : QWidget(parent)
{
    Tower *mageTower = new Tower();
    mageTower->type=2;
    mageTower->set(1);
    Tower *classicTower = new Tower();

    Monster *monster = new Monster();

    QGridLayout * grid = new QGridLayout(this);

    QLabel * classicTowerImage = new QLabel();
    classicTowerImage->setPixmap(classicTower->pixmap());
    grid->addWidget(classicTowerImage,1,1);

    QLabel *mageTowerImage = new QLabel();
    mageTowerImage->setPixmap(mageTower->pixmap());
    grid->addWidget(mageTowerImage,1,2);

    QLabel *classicTowerText = new QLabel();
    classicTowerText->setText(QString(tr("Classic Tower : \nNo specificities\nDamage : %1\nSpeed : %2\nCost : %3")).arg(classicTower->damage).arg(classicTower->speed).arg(classicTower->cost));
    grid->addWidget(classicTowerText,2,1);

    QLabel *mageTowerText = new QLabel();
    mageTowerText->setText(QString(tr("Mage Tower : \nDestroy ennemy shield\nDamage : %1\nSpeed : %2\nCost : %3")).arg(mageTower->damage).arg(mageTower->speed).arg(mageTower->cost));
    grid->addWidget(mageTowerText,2,2);

    QLabel *monsterImage = new QLabel;
    monsterImage->setPixmap(monster->pixmap());
    grid->addWidget(monsterImage,1,6);

    QLabel *monsterText = new QLabel;
    monsterText->setText(QString(tr("Monster 1 \nDamage : %1\nVelocity : %2\nHealth : %3")).arg(monster->dammage).arg(monster->velocity).arg(monster->hp));
    grid->addWidget(monsterText,2,6);

    QPushButton *exit = new QPushButton(tr("exit"));
    connect(exit,&QPushButton::clicked,this,[=]{emit finishEncyclo();});
    grid->addWidget(exit,6,2);
    //to do create label with tower and monsters attributes

}
