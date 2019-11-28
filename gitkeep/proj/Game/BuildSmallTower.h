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
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};



#endif // BUILDSMALLTOWER_H
