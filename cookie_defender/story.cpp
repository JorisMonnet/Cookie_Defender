#include "story.h"
#include <QLayout>

Story::Story(QWidget *parent) : QWidget(parent)
{

    QPushButton *exit = new QPushButton(tr("exit"));
    QVBoxLayout *vLay = new QVBoxLayout();
    vLay->addStretch();
    vLay->addWidget(exit);
    vLay->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(vLay);
    mainLayout->addStretch();


    connect(exit,&QPushButton::clicked,this,[=]{emit finishStory();});
}
