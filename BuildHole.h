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
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BUILDHOLE_H
