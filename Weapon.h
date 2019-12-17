#ifndef WEAPON_H
#define WEAPON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <Enemy.h>
#include <Robot.h>
class Weapon:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Weapon(int x,int y);
    int n = 1;
public slots:
    void fire();
    void rotate();
};

#endif // WEAPON_H
