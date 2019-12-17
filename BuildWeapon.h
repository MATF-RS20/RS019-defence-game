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
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BUILDWEAPON_H
