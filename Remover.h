#ifndef REMOVER_H
#define REMOVER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <Hole.h>
#include <Bomb.h>
#include <Cannon.h>
#include <TowerSmall.h>
#include <Weapon.h>
class Remover:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Remover(int x,int y);
public slots:
    void move();
};

#endif // REMOVER_H
