#ifndef WEAPONBULLETS_H
#define WEAPONBULLETS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>

class WeaponBullet1:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    WeaponBullet1(int x,int y);
public slots:
   void move_bullet1();

};
class WeaponBullet2:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    WeaponBullet2(int x,int y);
public slots:
   void move_bullet2();

};
class WeaponBullet3:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    WeaponBullet3(int x,int y);
public slots:
   void move_bullet3();

};



#endif // WEAPONBULLETS_H
