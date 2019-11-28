#ifndef TOWERSMALL_H
#define TOWERSMALL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <Enemy.h>
class TowerSmall:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    TowerSmall(int x,int y);
public slots:
    void fire();
};


#endif // TOWERSMALL_H
