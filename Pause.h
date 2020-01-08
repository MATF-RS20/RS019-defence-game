#ifndef PAUSE_H
#define PAUSE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Continue.h"
class Pause: public QGraphicsPixmapItem{
public:
    Pause();
    Continue* c;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAUSE_H
