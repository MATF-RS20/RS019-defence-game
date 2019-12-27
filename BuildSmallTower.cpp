#include "BuildSmallTower.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "TowerSmall.h"
#include <iostream>
#include "Game.h"
#include<QGraphicsOpacityEffect>
#include <QTimer>
extern Game* game;
BuildSmallTower::BuildSmallTower():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju kule

   QPixmap img(":/imgs/towerRound_sampleF_E.png");
   setPixmap(img.scaled(QSize(200,170)));
   setPos(-40,565);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(100);
}
//funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
void BuildSmallTower::wait()
{
    qreal op;
    if(game->score->score>= cost){
        op=static_cast <qreal>(1);
    }
    else{
        op=static_cast <qreal>(0.4);
    }
    setOpacity(op);
    setPos(-40,565);
}

void BuildSmallTower::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju kule i drzimo kursor on postaje kula
    if(game->score->score>=cost){
        QPixmap img(":/imgs/towerRound_sampleF_E.png");
        setCursor(img.scaled(QSize(200,200)));
    }

}
void BuildSmallTower::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi kula
    if(game->score->score>=cost){
        game->score->score-=cost;
        game->score->prints();
        TowerSmall * t = new TowerSmall(QCursor::pos().x()-150,QCursor::pos().y()-150);
        scene()->addItem(t);
        setCursor(Qt::ArrowCursor);
    }

}
