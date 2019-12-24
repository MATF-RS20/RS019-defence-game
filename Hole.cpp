#include "Hole.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include "Enemy.h"
#include "Robot.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
Hole::Hole(int x,int y):QObject(), QGraphicsPixmapItem()
{
    // Pravimo rupu
   QPixmap img(":/imgs/port2.png");
   setPixmap(img.scaled(QSize(70,70)));
   setPos(x,y);
}
