#include "BuildHole.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "Hole.h"
#include <iostream>
BuildHole::BuildHole():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju rupa

   QPixmap img(":/imgs/portal_orange.png");
   setPixmap(img.scaled(QSize(70,60)));
   setPos(475, 620);
}
void BuildHole::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju rupe i drzimo kursor on postaje rupa

     QPixmap img(":/imgs/portal_orange.png");
     setCursor(img.scaled(QSize(75,65)));

}
void BuildHole::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi rupa

    Hole * m = new Hole(QCursor::pos().x()-100,QCursor::pos().y()-100);
    scene()->addItem(m);
    setCursor(Qt::ArrowCursor);
}

