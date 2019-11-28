#ifndef EXITBTN_H
#define EXITBTN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class ExitBtn: public QGraphicsPixmapItem{
public:
    ExitBtn();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // EXITBTN_H
