#include "map.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Map *map=new Map();
    map->show();
    return a.exec();
}

