#ifndef BUILDTANK_H
#define BUILDTANK_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>

class BuildTank:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BuildTank();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    int cost=3;
public slots:
    void wait();

};
#endif // BUILDTANK_H
