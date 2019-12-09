#ifndef CANNONBULLET_H
#define CANNONBULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>

class CannonBullet1:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    CannonBullet1(int x,int y);
public slots:
   void move_bullet1();

};
class CannonBullet2:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    CannonBullet2(int x,int y);
public slots:
   void move_bullet2();

};
#endif // CANNONBULLET_H
