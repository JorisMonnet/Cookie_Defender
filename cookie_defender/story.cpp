#include "story.h"
#include <QLayout>
#include <QDebug>
#include <QFile>
#include <QLabel>

Story::Story(QWidget *parent) : QWidget(parent)
{
    QLabel *lab= new QLabel();
    lab->setTextFormat(Qt::AutoText);
    lab->setText(tr("For thousands of centuries, in the small funny village of Sevenans,\n"
                    "the Cook family hides and protects the sacred cookie's recipe of aunty Georgia.\n"
                    "This cookie is full of flavor and crispy but also with a bit of honey....\n"
                    "Hum this cookie is damn perfect !\n"
                    "By the past and currently the Cookie's War tears all the Sevenans's scholar on break time.\n\n"
                    "We need you ! The cookie needs you !\n"
                    "The war never stops ! \n"
                    "Go on soldier ! "));
    lab->setAlignment(Qt::AlignCenter);
    lab->setFont(QFont("Brush Script MT",25));

    QPushButton *exit = new QPushButton(tr("&Exit"));
    QVBoxLayout *vLay = new QVBoxLayout();
    vLay->addStretch();
    vLay->addWidget(lab);
    vLay->addStretch();
    vLay->addWidget(exit);
    vLay->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(vLay);
    mainLayout->addStretch();


    connect(exit,&QPushButton::clicked,this,[=]{emit finishStory();});
}
