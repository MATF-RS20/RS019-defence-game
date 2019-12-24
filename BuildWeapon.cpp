#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Weapon.h"
#include "BuildWeapon.h"
#include <iostream>
BuildWeapon::BuildWeapon():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju oruzje

   QPixmap img(":/imgs/weapon2.png");
   setPixmap(img.scaled(QSize(40,40)));
   setPos(340,633);
}
void BuildWeapon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju oruzje i drzimo kursor on postaje oruzje

     QPixmap img(":/imgs/weapon2.png");
     setCursor(img.scaled(QSize(40,40)));

}
void BuildWeapon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi oruzje

    Weapon * weapon = new Weapon(QCursor::pos().x()-85,QCursor::pos().y()-85);
    scene()->addItem(weapon);
    setCursor(Qt::ArrowCursor);
}

