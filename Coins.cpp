#include "Coins.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <QGraphicsScene>
#include "Enemy.h"
#include "Robot.h"
#include "WomanEnemy.h"
#include"Game.h"
Coins::Coins():QObject(), QGraphicsPixmapItem()
{

   QPixmap img(":/imgs/coin1.png");
   setPixmap(img.scaled(QSize(40,40)));
   setPos(25,15);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(200);
}
void Coins::wait()
{
    if (this->n == 1){
        setPos(25,15);
        QPixmap img(":/imgs/coin5.png");
        setPixmap(img.scaled(QSize(40,40)));
        this->n=2;
    }else if(this->n==2){
        setPos(40,15);
        QPixmap img(":/imgs/coin2.png");
        setPixmap(img.scaled(QSize(10,40)));
        this->n=3;
    }else if(this->n==3){
        setPos(25,15);
        QPixmap img(":/imgs/coin3.png");
        setPixmap(img.scaled(QSize(40,40)));
        this->n=4;
    }else if(this->n==4){
        setPos(25,15);
        QPixmap img(":/imgs/coin4.png");
        setPixmap(img.scaled(QSize(40,40)));
        this->n=5;
    }else if(this->n==5){
        setPos(25,15);
        QPixmap img(":/imgs/coin1.png");
        setPixmap(img.scaled(QSize(40,40)));
        this->n=1;
    }

}


