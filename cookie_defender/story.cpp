#include "story.h"
#include <QLayout>
#include <QDebug>
#include <QFile>
#include <QLabel>

Story::Story(QWidget *parent) : QWidget(parent)
{
    QLabel *lab= new QLabel();
    lab->setTextFormat(Qt::AutoText);
    lab->setText(tr("Depuis des temps immémoriaux, dans le jovial village de Sevenans, \nla famille Cook chérie et conserve précieusement "
                 "la recette du sacro-saint cookie : le cookie de tatie Georgette.\nCe cookie si tendre est fondant mais"
                 " en même temps croustillant et mielleux a\n par le passé déclenché moultes révoltes lors du quatre heure"
                 " journalier des écoles de toute la région. \n"
                 "Aujourd’hui la guerre continue ! \nLevez-vous et protégez le cookie dussiez-vous y laisser votre vie !\n\n"
                 "Soldat ! Le cookie a besoin de vous !"));
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
