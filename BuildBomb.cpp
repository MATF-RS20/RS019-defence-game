#include "BuildBomb.h"
#include <QObject>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include <QTimer>
#include "Player.h"
#include "Bomb.h"
#include"Game.h"
#include <QGraphicsOpacityEffect>

#include <iostream>
extern Game* game;
BuildBomb::BuildBomb():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju bombe

   QPixmap img(":/imgs/bomb.png");
   setPixmap(img.scaled(QSize(50,50)));
   setPos(785,620);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(100);
}
//funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
void BuildBomb::wait()
{
    qreal op;
    if(game->score->score>= cost){
        op=static_cast <qreal>(1);
    }
    else{
        op=static_cast <qreal>(0.4);
    }
    setOpacity(op);
    setPos(785,620);
}
void BuildBomb::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju bombe , kursor postaje bomba
    if(game->score->score>=cost){
        QPixmap img(":/imgs/bomb.png");
        setCursor(img.scaled(QSize(50,50)));
    }

}
void BuildBomb::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi bomba
    if(game->score->score>=cost){
        game->score->score-=cost;
        game->score->prints();
        Bomb * b = new Bomb(QCursor::pos().x()-100,QCursor::pos().y()-100);
        scene()->addItem(b);
        setCursor(Qt::ArrowCursor);
    }

}
