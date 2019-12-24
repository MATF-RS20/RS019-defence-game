#include "PlayAgain.h"
#include "Player.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

PlayAgain::PlayAgain(): QGraphicsPixmapItem(){
    //Dugme za ponovno pokretanje igrice

    QPixmap img(":/imgs/play_again.png");
    setPixmap(img.scaled(QSize(230,80)));
    setPos(540, 330);
}
bool PlayAgain::pressed=false;
void PlayAgain::mousePressEvent(QGraphicsSceneMouseEvent *event){
   // pressed=true;
}
