#include "BuildTank.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Tank.h"
#include <iostream>
BuildTank::BuildTank():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju tenka

   QPixmap img(":/imgs/tank.png");
   setPixmap(img.scaled(QSize(70,55)));
   setPos(175,620);
}
void BuildTank::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju tenka i drzimo kursor on postaje tenk

     QPixmap img(":/imgs/tank.png");
     setCursor(img.scaled(QSize(70,55)));

}
void BuildTank::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi tenk

    Tank * t = new Tank(QCursor::pos().x()-100,QCursor::pos().y()-130);
    scene()->addItem(t);
    setCursor(Qt::ArrowCursor);
}
