#include "encyclopedia.h"
#include "encyclowidg.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

Encyclopedia::Encyclopedia(QWidget *parent) : QWidget(parent)
{

    EncycloWidg *encycloWidg = new EncycloWidg();

    QPushButton *exit = new QPushButton(tr("&Exit"));
    exit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(exit,&QPushButton::clicked,this,[=]{emit finishEncyclo();});

    QHBoxLayout *hLay=new QHBoxLayout();
    hLay->addWidget(exit);

    QVBoxLayout *vLay = new QVBoxLayout();
    vLay->addWidget(encycloWidg);
    vLay->addStretch();
    vLay->addItem(hLay);
    vLay->addStretch();
    setLayout(vLay);

    QPalette pal = palette();
    pal.setBrush(QPalette::Window,QBrush(QPixmap(":/icones/backgroundStory.png")));
    setAutoFillBackground(true);
    setPalette(pal);
}
