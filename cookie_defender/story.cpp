#include "story.h"

Story::Story(QWidget *parent) : QWidget(parent)
{
    QLabel *label= new QLabel();
    label->setTextFormat(Qt::AutoText);
    label->setText(tr("For thousands of centuries, in the small funny village of Sevenans,\n"
                    "the Cook family hides and protects the sacred cookie's recipe of aunty Georgia.\n"
                    "This cookie is full of flavor and crispy but also with a bit of honey....\n"
                    "Hum this cookie is damn perfect !\n"
                    "By the past and currently the Cookie's War tears all the Sevenans's scholar on break time.\n\n"
                    "We need you ! The cookie needs you !\n"
                    "The war never stops ! \n"
                    "Go on soldier ! "));
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Brush Script MT",25));

    QPushButton *exit = new QPushButton(tr("&Exit"));
    QHBoxLayout *hLay =new QHBoxLayout();
    hLay->addStretch();
    hLay->addWidget(exit);
    hLay->addStretch();

    QVBoxLayout *vLay = new QVBoxLayout();
    vLay->addStretch();
    vLay->addWidget(label);
    vLay->addStretch();
    vLay->addItem(hLay);
    vLay->addStretch();
    setLayout(vLay);

    QPalette pal = palette();
    pal.setBrush(QPalette::Window,QBrush(QPixmap(":/icones/backgroundStory.png")));
    setAutoFillBackground(true);
    setPalette(pal);

    connect(exit,&QPushButton::clicked,this,[=]{emit finishStory();});
}
