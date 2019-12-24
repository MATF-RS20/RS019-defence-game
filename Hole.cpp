#include "Hole.h"
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include "Enemy.h"
#include "Robot.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Remover.h"
Hole::Hole(int x,int y):QObject(), QGraphicsPixmapItem()
{
    // Pravimo rupu
   QPixmap img(":/imgs/port2.png");
   setPixmap(img.scaled(QSize(70,70)));
   setPos(x,y);

   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(1500);
}


void Hole::wait()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Remover) ){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }

}

