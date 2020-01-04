#include "projectile.h"

Projectile::Projectile(QGraphicsPixmapItem*parent, QLine * projectilePath, int towerType) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(QString("../icones/projectile%1.png").arg(towerType)).scaled(20,20));
}
