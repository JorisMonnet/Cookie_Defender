#include "projectile.h"

Projectile::Projectile(int towerType)
{
    setPixmap(QPixmap(QString("../icones/projectile%1.png").arg(towerType)).scaled(20,20));
}

void Projectile::move(QPointF pos)
{
}
