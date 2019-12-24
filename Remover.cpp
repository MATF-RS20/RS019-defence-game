#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSize>
#include <QTimer>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Remover.h"
#include "Bomb.h"
#include "Cannon.h"
#include "Weapon.h"
#include "Hole.h"
#include "TowerSmall.h"

Remover::Remover(int x,int y):QObject(), QGraphicsPixmapItem()
{
   // Pravimo brisaca
   QPixmap img(":/imgs/remover.png");
   setPixmap(img.scaled(QSize(40,40)));
   setPos(x,y);

   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));
   timer->start(2000);
}

void Remover::move(){
    scene()->removeItem(this);
    delete this;
}
