#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Remover.h"
Remover::Remover(int x,int y):QObject(), QGraphicsPixmapItem()
{

   QPixmap img(":/imgs/remover.png");
   setPixmap(img.scaled(QSize(40,40)));
   setPos(x,y);
}
