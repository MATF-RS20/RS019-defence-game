#ifndef BUILDHOLE_H
#define BUILDHOLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>

class BuildHole:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BuildHole();
    int cost=2;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    //funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
    void wait();
};

#endif // BUILDHOLE_H
