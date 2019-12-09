#include "BuildCannon.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Cannon.h"
#include <iostream>
BuildCannon::BuildCannon():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju topa

   QPixmap img(":/imgs/enemy_ufoPurpleWeapon.png");
   setPixmap(img.scaled(QSize(50,50)));
   setPos(635,625);
}
void BuildCannon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju topa i drzimo kursor on postaje top

     QPixmap img(":/imgs/enemy_ufoPurpleWeapon.png");
     setCursor(img.scaled(QSize(50,50)));

}
void BuildCannon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi top

    Cannon * cannon = new Cannon(QCursor::pos().x()-100,QCursor::pos().y()-100);
    scene()->addItem(cannon);
    setCursor(Qt::ArrowCursor);
}
