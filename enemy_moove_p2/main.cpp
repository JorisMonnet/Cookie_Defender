#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *cookieDefender=new Game();
    cookieDefender->show();
    return a.exec();
}

