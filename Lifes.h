#ifndef LIFES_H
#define LIFES_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Lifes:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Lifes();
    int lifes = 3;
public slots:
    void wait();

};

#endif // LIFES_H
