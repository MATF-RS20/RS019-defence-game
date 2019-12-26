#include "BuildTank.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Tank.h"
#include <iostream>
#include <QGraphicsOpacityEffect>
#include<QTimer>
#include"Game.h"
extern Game* game;
BuildTank::BuildTank():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju tenka

   QPixmap img(":/imgs/tank.png");
   setPixmap(img.scaled(QSize(70,55)));
   setPos(175,620);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(100);
}
//funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
void BuildTank::wait()
{
    qreal op;
    if(game->score->score>= cost){
        op=static_cast <qreal>(1);
    }
    else{
        op=static_cast <qreal>(0.4);
    }
    setOpacity(op);
    setPos(175,620);
}
void BuildTank::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju tenka i drzimo kursor on postaje tenk
    if(game->score->score>=cost){
        QPixmap img(":/imgs/tank.png");
        setCursor(img.scaled(QSize(70,55)));
    }


}
void BuildTank::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi tenk

    if(game->score->score>=cost){
        game->score->score-=cost;
        game->score->prints();
        Tank * t = new Tank(QCursor::pos().x()-100,QCursor::pos().y()-130);
        scene()->addItem(t);
        setCursor(Qt::ArrowCursor);
    }

}
