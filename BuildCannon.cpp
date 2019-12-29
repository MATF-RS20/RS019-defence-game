#include "BuildCannon.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Cannon.h"
#include "Game.h"
#include <iostream>
#include <QTimer>
#include<QGraphicsOpacityEffect>
extern Game* game;
BuildCannon::BuildCannon():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju topa
   QPixmap img(":/imgs/enemy_ufoPurpleWeapon.png");
   setPixmap(img.scaled(QSize(50,50)));
   setPos(635,625);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(100);
}
//funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
void BuildCannon::wait()
{
    qreal op;
    if(game->score->score>= cost && game->started && !game->lost){
        op=static_cast <qreal>(1);
    }
    else{
        op=static_cast <qreal>(0.4);
    }
    setOpacity(op);
    setPos(635,625);
}

void BuildCannon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju topa i drzimo kursor on postaje top
    if(game->score->score>=cost && game->started && !game->lost){
        QPixmap img(":/imgs/enemy_ufoPurpleWeapon.png");
        setCursor(img.scaled(QSize(50,50)));
    }


}
void BuildCannon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi top
    if(game->score->score>=cost && game->started && !game->lost){
        game->score->score-=cost;
        game->score->prints();
        Cannon * cannon = new Cannon(QCursor::pos().x()-100,QCursor::pos().y()-100);
        scene()->addItem(cannon);
        setCursor(Qt::ArrowCursor);
    }

}
