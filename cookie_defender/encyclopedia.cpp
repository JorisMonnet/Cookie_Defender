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

    QHBoxLayout *hLay=new QHBoxLayout();
    hLay->addWidget(exit);

    QVBoxLayout *vLay = new QVBoxLayout();
    hLay->addWidget(exit);
    vLay->addWidget(encycloWidg);
    vLay->addStretch();
    vLay->addItem(hLay);
    vLay->addStretch();
    setLayout(vLay);
}


