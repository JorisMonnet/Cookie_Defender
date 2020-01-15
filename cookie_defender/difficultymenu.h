#ifndef DIFFICULTYMENU_H
#define DIFFICULTYMENU_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>

class DifficultyMenu : public QWidget
{
    Q_OBJECT
public:
    DifficultyMenu(QWidget *parent=nullptr);
signals:
    void difficultySignal(int);
    void exitDifficultyMenu(void);
};

#endif // DIFFICULTYMENU_H
