#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ui_formEncyclo.h"

/**
* This class allow to the player to see the atributes of the differents ennemies and towers
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
*/

class Encyclopedia : public QWidget
{
    Q_OBJECT
public:
    Encyclopedia(QWidget *parent=nullptr);
signals:
    void finishEncyclo(void);
};

#endif // ENCYCLOPEDIA_H
