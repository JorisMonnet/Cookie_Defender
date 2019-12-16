#pragma once

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
