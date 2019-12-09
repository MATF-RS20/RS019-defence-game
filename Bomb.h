#ifndef BOMB_H
#define BOMB_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <Enemy.h>
#include <Robot.h>
#include "WomanEnemy.h"

class Bomb:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bomb(int x,int y);
    int n=1;
public slots:
    void wait();
    void explosion();
};
#endif // BOMB_H
