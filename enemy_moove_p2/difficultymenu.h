#ifndef DIFFICULTYMENU_H
#define DIFFICULTYMENU_H

#include <QWidget>

class DifficultyMenu : public QWidget
{
    Q_OBJECT
public:
    DifficultyMenu(QWidget *parent=nullptr);
signals:
    void difficultySignal(int id);
    void exitDifficultyMenu();
};

#endif // DIFFICULTYMENU_H
