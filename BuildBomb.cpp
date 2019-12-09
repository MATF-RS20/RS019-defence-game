#include "BuildBomb.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Bomb.h"
#include <iostream>
BuildBomb::BuildBomb():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju bombe

   QPixmap img(":/imgs/bomb.png");
   setPixmap(img.scaled(QSize(50,50)));
   setPos(785,620);
}
void BuildBomb::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju bombe , kursor postaje bomba

     QPixmap img(":/imgs/bomb.png");
     setCursor(img.scaled(QSize(50,50)));

}
void BuildBomb::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi bomba

    Bomb * b = new Bomb(QCursor::pos().x()-100,QCursor::pos().y()-100);

    scene()->addItem(b);
    setCursor(Qt::ArrowCursor);
}
