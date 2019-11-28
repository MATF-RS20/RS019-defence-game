#ifndef TOWERSMALLBULLET_H
#define TOWERSMALLBULLET_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>

class TowerSmallBullet:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    TowerSmallBullet(int x,int y);
public slots:
   void move_bullet();

};
#endif // TOWERSMALLBULLET_H
