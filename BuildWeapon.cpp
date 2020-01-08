#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Weapon.h"
#include "BuildWeapon.h"
#include <iostream>
#include "Game.h"
#include<QGraphicsOpacityEffect>
#include <QTimer>
extern Game* game;
BuildWeapon::BuildWeapon():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju oruzje

   QPixmap img(":/imgs/weapon2.png");
   setPixmap(img.scaled(QSize(40,40)));
   setPos(340,633);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(100);
}
//funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
void BuildWeapon::wait()
{
    qreal op;
    if(game->score->score>= cost  && game->started && !game->lost && !game->pause){
        op=static_cast <qreal>(1);
    }
    else{
        op=static_cast <qreal>(0.4);
    }
    setOpacity(op);
    setPos(340,633);

}
void BuildWeapon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju oruzje i drzimo kursor on postaje oruzje
    if(game->score->score>=cost && game->started && !game->lost && !game->pause){
        QPixmap img(":/imgs/weapon2.png");
        setCursor(img.scaled(QSize(40,40)));

    }
}
void BuildWeapon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi oruzje
    if(game->score->score>=cost && game->started && !game->lost && !game->pause){
        game->score->score-=cost;
        game->score->prints();
        Weapon * weapon = new Weapon(QCursor::pos().x()-85,QCursor::pos().y()-85);
        scene()->addItem(weapon);
        setCursor(Qt::ArrowCursor);
    }

}

