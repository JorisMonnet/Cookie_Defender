#include "widget.h"

#include <QTimer>


Widget::Widget(QGraphicsView *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    this->setScene(scene);
    this->resize(800, 600);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSceneRect(-width()/2,-height()/2,width(),height());
    setRenderHint(QPainter::Antialiasing, false);
    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode( QGraphicsView::SmartViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode( QGraphicsView::FullViewportUpdate);

    timer = new QTimer(this);

}


