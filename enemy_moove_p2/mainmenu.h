#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>

class MainMenu : public QWidget
{
public:
    MainMenu(QWidget *parent = nullptr);
    QPushButton *options;
    QPushButton *encyclo;
    QPushButton *play;
};
#endif // MAINMENU_H
