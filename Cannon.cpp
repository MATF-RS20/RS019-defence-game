#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <CannonBullet.h>
#include "Enemy.h"
#include "Robot.h"
#include "Cannon.h"
#include "Remover.h"
#include "Zombie.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

#include "Game.h"

extern Game* game;
Cannon::Cannon(int x,int y):QObject(), QGraphicsPixmapItem()
{
    // Pravimo mali topa na datoj lokaciji
   QPixmap img(":/imgs/enemy_ufoPurpleWeapon.png");
   setPixmap(img.scaled(QSize(50,50)));
   setPos(x,y);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(fire()));
   timer->start(1500);

}

void Cannon::fire()
{
    if(!game->lost && !game->pause){
    // Na odredjenom vremenskom intervalu top puca
   CannonBullet1 * cb1 = new CannonBullet1(x(),y());
   CannonBullet2 * cb2 = new CannonBullet2(x(),y());
    scene()->addItem(cb1);
    scene()->addItem(cb2);

    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Remover) ){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
}
