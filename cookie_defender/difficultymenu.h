#ifndef DIFFICULTYMENU_H
#define DIFFICULTYMENU_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>

/**
 * This Class handle the choose of difficulty with buttons
 *
 * @author Ugo Crucy,Joris Monnet,Adrien Paysant
 * @version
 */

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
