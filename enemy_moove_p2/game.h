#ifndef GAME_H
#define GAME_H

#include "map.h"

class Map;

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // GAME_H
