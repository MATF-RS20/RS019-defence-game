#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSize>
#include <QTimer>
#include <vector>
#include <iostream>
#include <stdlib.h>

#include "Lifes.h"
#include "Player.h"

Lifes::Lifes():QObject(), QGraphicsPixmapItem()
{
   QPixmap img(":/imgs/3hearts.png");
   setPixmap(img.scaled(QSize(150,50)));
   setPos(110, 10);

   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(100);
}

void Lifes::wait()
{
    if(Player::lifes==3){
        QPixmap img(":/imgs/3hearts.png");
        setPixmap(img.scaled(QSize(150,50)));
        setPos(150, 10);
    }else if(Player::lifes==2){
        QPixmap img(":/imgs/2hearts.png");
        setPixmap(img.scaled(QSize(150,50)));
        setPos(150, 10);
    }else if(Player::lifes==1){
        QPixmap img(":/imgs/1hearts.png");
        setPixmap(img.scaled(QSize(150,50)));
        setPos(150, 10);
    }else{
        QPixmap img(":/imgs/0hearts.png");
        setPixmap(img.scaled(QSize(150,50)));
        setPos(150, 10);
    }
}
