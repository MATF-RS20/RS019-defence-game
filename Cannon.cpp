#include "Cannon.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <CannonBullet.h>
#include "Enemy.h"
#include "Robot.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
Cannon::Cannon(int x,int y):QObject(), QGraphicsPixmapItem()
{
    // Pravimo top na datoj lokaciji
   QPixmap img(":/imgs/enemy_ufoPurpleWeapon.png");
   setPixmap(img.scaled(QSize(50,50)));
   setPos(x,y);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(fire()));
   timer->start(2000);


}

void Cannon::fire()
{
    // Na odredjenom vremenskom intervalu top puca u sva pravca
   CannonBullet1 * cb1 = new CannonBullet1(x(),y());
   CannonBullet2 * cb2 = new CannonBullet2(x(),y());
    scene()->addItem(cb1);
    scene()->addItem(cb2);

}
