#ifndef BUILDWEAPON_H
#define BUILDWEAPON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>

class BuildWeapon:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BuildWeapon();
    int cost=6;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    //funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
    void wait();
};

#endif // BUILDWEAPON_H
