#pragma once

#include "particleemitter.h"

#include <QGraphicsView>
#include <QTime>
#include <QGraphicsEllipseItem>
#include <QVector2D>

class QGraphicsScene;

class Widget : public QGraphicsView
{
public:
    Widget(QGraphicsView *parent = nullptr);

private:
    QGraphicsScene *scene = nullptr;
    QTimer *timer = nullptr;
    QVector<QGraphicsEllipseItem*> ellipses;
    QTime time;

    ParticleEmitter<QVector<Particle<QVector2D>>> emmiter;

};