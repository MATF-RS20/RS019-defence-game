#include "Play.h"
#include "Game.h"
#include <QApplication>

extern Game * game;
Play::Play(): QGraphicsPixmapItem(){
    //Dugme za pokretanje igrice

    QPixmap img(":/imgs/play.png");
    setPixmap(img.scaled(QSize(290,100)));
    setPos(505,270);
}

void Play::mousePressEvent(QGraphicsSceneMouseEvent *event){
   game->begin();
}
