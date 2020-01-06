#include "projectile.h"

Projectile::Projectile(QPoint pos, int towerType)
{
    setPixmap(QPixmap(QString("../icones/projectile%1.png").arg(towerType)).scaled(20,20));
    this->pos = pos;
}

void Projectile::move(int dx, int dy, QPoint point)
{
    this->setPos(QPoint(point.x() + dx -10, point.y() + dy -10));
}
