#ifndef TANKROCKET_H
#define TANKROCKET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>

class TankRocket:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    TankRocket(int x,int y);
    void RocketExplode();
public slots:
   void move_rocket();
};
#endif // TANKROCKET_H
