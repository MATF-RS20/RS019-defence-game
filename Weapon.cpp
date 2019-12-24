#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <WeaponBullets.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Weapon.h"
#include "Enemy.h"
#include "Robot.h"
#include "Remover.h"

Weapon::Weapon(int x,int y):QObject(), QGraphicsPixmapItem()
{
   // Pravimo oruzje na datoj lokaciji
   QPixmap img(":/imgs/weapon2.png");
   setPixmap(img.scaled(QSize(43,43)));
   setPos(x,y);

   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(fire()));
   timer->start(2000);

   QTimer * timer2 = new QTimer(this);
   connect(timer2,SIGNAL(timeout()),this,SLOT(rotate()));
   timer2->start(500);

}

void Weapon::fire()
{
    // Na odredjenom vremenskom intervalu oruzje puca
   WeaponBullet1 * tb1 = new WeaponBullet1(x(),y());
   WeaponBullet2 * tb2 = new WeaponBullet2(x(),y());
   WeaponBullet3 * tb3 = new WeaponBullet3(x(),y());
    scene()->addItem(tb1);
    scene()->addItem(tb2);
    scene()->addItem(tb3);

    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Remover) ){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
}


void Weapon::rotate(){

    if (this->n == 1){
        QPixmap img(":/imgs/weapon2.png");
        setPixmap(img.scaled(QSize(43, 43)));
        this->n=2;
    }else if(this->n==2){
        QPixmap img(":/imgs/weapon2.png");
        QMatrix rm;
        rm.rotate(23);
        img = img.transformed(rm);
        setPixmap(img.scaled(QSize(43, 43)));
        this->n=3;
    }else if(this->n==2){
        QPixmap img(":/imgs/weapon2.png");
        QMatrix rm;
        rm.rotate(70);
        img = img.transformed(rm);
        setPixmap(img.scaled(QSize(43, 43)));
        this->n=3;
    }else if(this->n==3){
        QPixmap img(":/imgs/weapon2.png");
        QMatrix rm;
        rm.rotate(43);
        img = img.transformed(rm);
        setPixmap(img.scaled(QSize(43, 43)));
        this->n=1;
    }


}
