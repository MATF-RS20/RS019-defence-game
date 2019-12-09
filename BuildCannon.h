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
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};


#endif // BUILDCANNON_H
