#ifndef TANK_H
#define TANK_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <Enemy.h>
class Tank:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tank(int x,int y);
public slots:
    void fire();
};

#endif // TANK_H
