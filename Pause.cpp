#include "Pause.h"
#include "Continue.h"
#include "Game.h"
#include <QApplication>

extern Game * game;
Pause::Pause(): QGraphicsPixmapItem(){
    //Dugme za pauziranje igrice

    QPixmap img(":/imgs/pause.png");
    setPixmap(img);
    setPos(1190,0);
}

void Pause::mousePressEvent(QGraphicsSceneMouseEvent *event){
    game->paused();
}
