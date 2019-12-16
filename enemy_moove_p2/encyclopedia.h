#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H

#include <QWidget>

class Encyclopedia : public QWidget
{
    Q_OBJECT
public:
    Encyclopedia(QWidget *parent=nullptr);
signals:
    void finishEncyclo();
};

#endif // ENCYCLOPEDIA_H
