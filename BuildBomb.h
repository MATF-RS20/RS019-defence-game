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
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};
#endif // BUILDBOMB_H
