#ifndef BUILDBOMB_H
#define BUILDBOMB_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>

class BuildBomb:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BuildBomb();
    int cost=5;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    //funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
    void wait();
};
#endif // BUILDBOMB_H
