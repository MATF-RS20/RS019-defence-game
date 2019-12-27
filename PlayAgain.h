#ifndef PLAYAGAIN_H
#define PLAYAGAIN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class PlayAgain: public QGraphicsPixmapItem{
public:
    PlayAgain();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif
