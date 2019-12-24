#ifndef HOLE_H
#define HOLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Hole:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hole(int x,int y);
public slots:
    void wait();
};

#endif // HOLE_H
