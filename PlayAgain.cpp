#include "PlayAgain.h"
#include "Player.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "Game.h"
extern Game* game;
PlayAgain::PlayAgain(): QGraphicsPixmapItem(){
    //Dugme za ponovno pokretanje igrice

    QPixmap img(":/imgs/play_again.png");
    setPixmap(img.scaled(QSize(230,80)));
    setPos(540, 330);
}

void PlayAgain::mousePressEvent(QGraphicsSceneMouseEvent *event){
     game->reset();
}
