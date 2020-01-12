/********************************************************************************
** Form generated from reading UI file 'formEncyclo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMENCYCLO_H
#define UI_FORMENCYCLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formEncyclo
{
public:
    QVBoxLayout *verticalLayout_6;
    QLabel *labelTitleEncyclo;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelTowerText;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelTowerPix;
    QSpacerItem *verticalSpacer;
    QLabel *labelTowerCarac_cost;
    QLabel *labelTowerCarac_range;
    QLabel *labelTowerCarac_damage;
    QLabel *labelTowerCarac_fireRate;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnTower;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelMonsterText;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelMonsterPix;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelMonsterCarac_hp;
    QLabel *labelMonsterCarac_shield;
    QLabel *labelMonsterCarac_damage;
    QLabel *labelMonsterCarac_speed;
    QLabel *labelMonsterCarac_reward;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnMonster;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelTowerLvl;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *formEncyclo)
    {
        if (formEncyclo->objectName().isEmpty())
            formEncyclo->setObjectName(QString::fromUtf8("formEncyclo"));
        formEncyclo->resize(908, 630);
        verticalLayout_6 = new QVBoxLayout(formEncyclo);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        labelTitleEncyclo = new QLabel(formEncyclo);
        labelTitleEncyclo->setObjectName(QString::fromUtf8("labelTitleEncyclo"));
        labelTitleEncyclo->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(labelTitleEncyclo);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_6->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelTowerText = new QLabel(formEncyclo);
        labelTowerText->setObjectName(QString::fromUtf8("labelTowerText"));
        labelTowerText->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelTowerText);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelTowerPix = new QLabel(formEncyclo);
        labelTowerPix->setObjectName(QString::fromUtf8("labelTowerPix"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTowerPix->sizePolicy().hasHeightForWidth());
        labelTowerPix->setSizePolicy(sizePolicy);
        labelTowerPix->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(labelTowerPix);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer);

        labelTowerCarac_cost = new QLabel(formEncyclo);
        labelTowerCarac_cost->setObjectName(QString::fromUtf8("labelTowerCarac_cost"));
        labelTowerCarac_cost->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelTowerCarac_cost);

        labelTowerCarac_range = new QLabel(formEncyclo);
        labelTowerCarac_range->setObjectName(QString::fromUtf8("labelTowerCarac_range"));
        labelTowerCarac_range->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelTowerCarac_range);

        labelTowerCarac_damage = new QLabel(formEncyclo);
        labelTowerCarac_damage->setObjectName(QString::fromUtf8("labelTowerCarac_damage"));
        labelTowerCarac_damage->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelTowerCarac_damage);

        labelTowerCarac_fireRate = new QLabel(formEncyclo);
        labelTowerCarac_fireRate->setObjectName(QString::fromUtf8("labelTowerCarac_fireRate"));
        labelTowerCarac_fireRate->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelTowerCarac_fireRate);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btnTower = new QPushButton(formEncyclo);
        btnTower->setObjectName(QString::fromUtf8("btnTower"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnTower->sizePolicy().hasHeightForWidth());
        btnTower->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(btnTower);


        verticalLayout_4->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelMonsterText = new QLabel(formEncyclo);
        labelMonsterText->setObjectName(QString::fromUtf8("labelMonsterText"));
        labelMonsterText->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelMonsterText);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelMonsterPix = new QLabel(formEncyclo);
        labelMonsterPix->setObjectName(QString::fromUtf8("labelMonsterPix"));
        sizePolicy.setHeightForWidth(labelMonsterPix->sizePolicy().hasHeightForWidth());
        labelMonsterPix->setSizePolicy(sizePolicy);
        labelMonsterPix->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(labelMonsterPix);


        verticalLayout_5->addLayout(horizontalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer_2);

        labelMonsterCarac_hp = new QLabel(formEncyclo);
        labelMonsterCarac_hp->setObjectName(QString::fromUtf8("labelMonsterCarac_hp"));
        labelMonsterCarac_hp->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelMonsterCarac_hp);

        labelMonsterCarac_shield = new QLabel(formEncyclo);
        labelMonsterCarac_shield->setObjectName(QString::fromUtf8("labelMonsterCarac_shield"));
        labelMonsterCarac_shield->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelMonsterCarac_shield);

        labelMonsterCarac_damage = new QLabel(formEncyclo);
        labelMonsterCarac_damage->setObjectName(QString::fromUtf8("labelMonsterCarac_damage"));
        labelMonsterCarac_damage->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelMonsterCarac_damage);

        labelMonsterCarac_speed = new QLabel(formEncyclo);
        labelMonsterCarac_speed->setObjectName(QString::fromUtf8("labelMonsterCarac_speed"));
        labelMonsterCarac_speed->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelMonsterCarac_speed);

        labelMonsterCarac_reward = new QLabel(formEncyclo);
        labelMonsterCarac_reward->setObjectName(QString::fromUtf8("labelMonsterCarac_reward"));
        labelMonsterCarac_reward->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelMonsterCarac_reward);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnMonster = new QPushButton(formEncyclo);
        btnMonster->setObjectName(QString::fromUtf8("btnMonster"));
        sizePolicy1.setHeightForWidth(btnMonster->sizePolicy().hasHeightForWidth());
        btnMonster->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(btnMonster);


        verticalLayout_5->addLayout(horizontalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        labelTowerLvl = new QLabel(formEncyclo);
        labelTowerLvl->setObjectName(QString::fromUtf8("labelTowerLvl"));
        labelTowerLvl->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelTowerLvl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_3);


        retranslateUi(formEncyclo);

        QMetaObject::connectSlotsByName(formEncyclo);
    } // setupUi

    void retranslateUi(QWidget *formEncyclo)
    {
        formEncyclo->setWindowTitle(QCoreApplication::translate("formEncyclo", "Form", nullptr));
        labelTitleEncyclo->setText(QCoreApplication::translate("formEncyclo", "<html><head/><body><p><span style=\" font-size:25pt;\">Cookie Defender Encyclopedia</span></p></body></html>", nullptr));
        labelTowerText->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelTowerPix->setText(QString());
        labelTowerCarac_cost->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelTowerCarac_range->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelTowerCarac_damage->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelTowerCarac_fireRate->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        btnTower->setText(QCoreApplication::translate("formEncyclo", "Other Tower", nullptr));
        labelMonsterText->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelMonsterPix->setText(QString());
        labelMonsterCarac_hp->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelMonsterCarac_shield->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelMonsterCarac_damage->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelMonsterCarac_speed->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        labelMonsterCarac_reward->setText(QCoreApplication::translate("formEncyclo", "TextLabel", nullptr));
        btnMonster->setText(QCoreApplication::translate("formEncyclo", "Other Enemy", nullptr));
        labelTowerLvl->setText(QCoreApplication::translate("formEncyclo", "<html><head/><body><p><span style=\" font-size:16pt;\">Tower Level Evolution :</span></p><p><span style=\" font-size:16pt;\">- Cost increases of 50 by level</span></p><p><span style=\" font-size:16pt;\">- Range increases by 35 by level</span></p><p><span style=\" font-size:16pt;\">- Firerate increases by 1 by level</span></p><p><span style=\" font-size:16pt;\">- Damage increases by 5 by level</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formEncyclo: public Ui_formEncyclo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMENCYCLO_H
