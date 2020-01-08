#ifndef CONTINUE_H
#define CONTINUE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Continue: public QGraphicsPixmapItem{
public:
    Continue();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


#endif // CONTINUE_H
