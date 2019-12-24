#ifndef BUILDREMOVER_H
#define BUILDREMOVER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>
#include <stdbool.h>

class BuildRemover:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bool setRemover = false;
    BuildRemover();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BUILDREMOVER_H
