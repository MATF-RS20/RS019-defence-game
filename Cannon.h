#ifndef CANNON_H
#define CANNON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "Enemy.h"
class Cannon:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Cannon(int x,int y);
public slots:
    void fire();
};
#endif // CANNON_H
