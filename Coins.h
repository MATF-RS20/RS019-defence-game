#ifndef COINS_H
#define COINS_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
class Coins:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Coins();
    int n=1;
public slots:
    void wait();
};
#endif // COINS_H
