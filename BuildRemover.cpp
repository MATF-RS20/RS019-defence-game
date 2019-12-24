#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "BuildRemover.h"
#include <QTimer>
#include "Remover.h"
#include <iostream>
BuildRemover::BuildRemover():QObject(), QGraphicsPixmapItem()
{
    // Pravimo ikonicu na ekranu za izgradnju rupa

   QPixmap img(":/imgs/remover.png");
   setPixmap(img.scaled(QSize(40,40)));
   setPos(1200, 637);
}
void BuildRemover::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Kada kliknemo na ikonicu za izgradnju kule i drzimo kursor on postaje kula

     QPixmap img(":/imgs/remover.png");
     setCursor(img.scaled(QSize(35,35)));

}
void BuildRemover::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //Kada pustimo kursor na nekoj lokaciji na njoj se pravi kula

    Remover * m = new Remover(QCursor::pos().x()-90,QCursor::pos().y()-90);
    scene()->addItem(m);
    setCursor(Qt::ArrowCursor);

    setRemover = true;
}
