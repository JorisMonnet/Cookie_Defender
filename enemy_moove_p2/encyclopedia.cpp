#include "encyclopedia.h"
#include <QPushButton>
#include <QGridLayout>
//#include <QLabel>

Encyclopedia::Encyclopedia(QWidget *parent) : QWidget(parent)
{
    QGridLayout * grid = new QGridLayout(this);
    QPushButton *exit = new QPushButton(tr("exit"));
    connect(exit,&QPushButton::clicked,this,[=]{
        emit finishEncyclo();
    });
    grid->addWidget(exit,3,2);
    //to do create label with tower and monsters attributes


}
