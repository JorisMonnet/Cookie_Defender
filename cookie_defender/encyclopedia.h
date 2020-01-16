#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ui_formEncyclo.h"

/**
* Description of the class
*
* @author	Ugo Crucy,Joris Monnet,Adrien Paysant
* @version	Number of the version
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
