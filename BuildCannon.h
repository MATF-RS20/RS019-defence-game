#ifndef BUILDCANNON_H
#define BUILDCANNON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>

class BuildCannon:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BuildCannon();
    int cost=4;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    //funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
    void wait();
};


#endif // BUILDCANNON_H
