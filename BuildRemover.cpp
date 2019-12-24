#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QApplication>
#include <QString>
#include "BuildRemover.h"
#include "Remover.h"
#include <iostream>
BuildRemover::BuildRemover():QObject(), QGraphicsPixmapItem()
{
   QPixmap img(":/imgs/remover.png");
   setPixmap(img.scaled(QSize(40,40)));
   setPos(1200, 625);
}
void BuildRemover::mousePressEvent(QGraphicsSceneMouseEvent *event){

     QPixmap img(":/imgs/remover.png");
     setCursor(img.scaled(QSize(35,35)));

}
void BuildRemover::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

    Remover * m = new Remover(QCursor::pos().x()-90,QCursor::pos().y()-90);
    scene()->addItem(m);
    setCursor(Qt::ArrowCursor);
}

