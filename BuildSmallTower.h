#ifndef BUILDSMALLTOWER_H
#define BUILDSMALLTOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>

class BuildSmallTower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BuildSmallTower();
    int cost=3;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    //funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
    void wait();
};



#endif // BUILDSMALLTOWER_H
