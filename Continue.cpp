#include "Continue.h"
#include "Game.h"
#include <QApplication>

extern Game * game;
Continue::Continue(): QGraphicsPixmapItem(){
    //Dugme za pauziranje igrice

    QPixmap img(":/imgs/continue.png");
    setPixmap(img.scaled(QSize(300,100)));
    setPos(500,250);
}

void Continue::mousePressEvent(QGraphicsSceneMouseEvent *event){
    game->continue_game();
}
