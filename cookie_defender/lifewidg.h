#ifndef LIFEWIDG_H
#define LIFEWIDG_H

#include <QWidget>
#include <QRectF>

class lifeWidg
{
public:
    lifeWidg(int _with,int _height);
    QRectF *rectRed;
    QRectF *rectGreen;
    void update();
};

#endif // LIFEWIDG_H
