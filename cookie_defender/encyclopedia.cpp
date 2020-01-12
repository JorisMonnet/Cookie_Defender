#include "encyclopedia.h"
#include <QPushButton>
#include <QLayout>
#include "encyclowidg.h"


Encyclopedia::Encyclopedia(QWidget *parent) : QWidget(parent)
{
    EncycloWidg *encycloWidg=new EncycloWidg();

    QPushButton *exit = new QPushButton(tr("&Exit"));
    exit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(exit,&QPushButton::clicked,this,[=]{emit finishEncyclo();});

    QVBoxLayout *vLay = new QVBoxLayout();
    vLay->addWidget(encycloWidg);
    vLay->addStretch();
    vLay->addWidget(exit);
    vLay->addStretch();
    setLayout(vLay);
}


