#include "BuildHole.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Hole.h"
#include <iostream>
#include "Game.h"
#include <QGraphicsOpacityEffect>
#include <QTimer>
extern Game* game;
BuildHole::BuildHole():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju rupa
    QPixmap img(":/imgs/portal_orange.png");
    setPixmap(img.scaled(QSize(70,60)));
    setPos(475, 620);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
    timer->start(100);
 }
//funkcija koja proverava da li ima novca za to oruzje i ako nema zamagljuje objekat
 void BuildHole::wait()
 {
     qreal op;
     if(game->score->score>= cost && game->started && !game->lost){
         op=static_cast <qreal>(1);
     }
     else{
         op=static_cast <qreal>(0.4);
     }
     setOpacity(op);
     setPos(475, 620);
 }
void BuildHole::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju kule i drzimo kursor on postaje kula
    if(game->score->score>=cost && game->started && !game->lost){
        QPixmap img(":/imgs/portal_orange.png");
        setCursor(img.scaled(QSize(75,65)));
    }

}
void BuildHole::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi kula
    if(game->score->score>=cost && game->started && !game->lost){
        game->score->score-=cost;
        game->score->prints();
        Hole * m = new Hole(QCursor::pos().x()-100,QCursor::pos().y()-100);
        scene()->addItem(m);
        setCursor(Qt::ArrowCursor);
    }

}

