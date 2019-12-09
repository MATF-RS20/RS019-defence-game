#include "BuildSmallTower.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "Player.h"
#include "TowerSmall.h"
#include <iostream>
BuildSmallTower::BuildSmallTower():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju kule

   QPixmap img(":/imgs/towerRound_sampleF_E.png");
   setPixmap(img.scaled(QSize(200,170)));
   setPos(-40,565);
}
void BuildSmallTower::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju kule i drzimo kursor on postaje kula

     QPixmap img(":/imgs/towerRound_sampleF_E.png");
     setCursor(img.scaled(QSize(200,200)));

}
void BuildSmallTower::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi kula

    TowerSmall * t = new TowerSmall(QCursor::pos().x()-100,QCursor::pos().y()-130);
    scene()->addItem(t);
    setCursor(Qt::ArrowCursor);
}
