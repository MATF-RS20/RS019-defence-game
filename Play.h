#ifndef PLAY_H
#define PLAY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Play: public QGraphicsPixmapItem{
public:
    Play();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


#endif // PLAY_H
