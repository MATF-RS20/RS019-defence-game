#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "WeaponBullets.h"
#include "Enemy.h"
#include "Robot.h"
#include "WomanEnemy.h"
#include "Zombie.h"

WeaponBullet1::WeaponBullet1(int x,int y):QObject(),QGraphicsPixmapItem(){
    QPixmap img(":/imgs/laser5.png");
    setPixmap(img.scaled(QSize(4, 20)));
    setPos(x+20,y-5);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_bullet1()));
    timer->start(100);
}


WeaponBullet2::WeaponBullet2(int x,int y):QObject(),QGraphicsPixmapItem(){
    QPixmap img(":/imgs/laser5.png");
    setPixmap(img.scaled(QSize(4, 20)));
    setPos(x+20,y-5);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_bullet2()));
    timer->start(100);
}

WeaponBullet3::WeaponBullet3(int x,int y):QObject(),QGraphicsPixmapItem(){
    QPixmap img(":/imgs/laser5.png");
    QMatrix rm;
    rm.rotate(90);
    img = img.transformed(rm);
    setPixmap(img.scaled(QSize(20, 4)));
    setPos(x-5,y+20);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_bullet3()));
    timer->start(100);
}

void WeaponBullet1::move_bullet1(){
    // COALISION DETECTION : preuzeto sa STACKOVERFLOW
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy)
                    || typeid(*(colliding_items[i])) == typeid(Robot)
                    || typeid(*(colliding_items[i])) == typeid(Zombie)
                    || typeid(*(colliding_items[i])) == typeid(WomanEnemy)){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    setPos(x(),y()-40);
    if(pos().x() <= 0 ){
        scene()->removeItem(this);
        delete this;
    }
}


void WeaponBullet2::move_bullet2(){
    // COALISION DETECTION : preuzeto sa STACKOVERFLOW
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy)
                    || typeid(*(colliding_items[i])) == typeid(Robot)
                    || typeid(*(colliding_items[i])) == typeid(Zombie)
                    || typeid(*(colliding_items[i])) == typeid(WomanEnemy)){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    setPos(x(),y()+40);
    if(pos().x() <= 0 ){
        scene()->removeItem(this);
        delete this;
    }
}




void WeaponBullet3::move_bullet3(){
    // COALISION DETECTION : preuzeto sa STACKOVERFLOW
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy)
                    || typeid(*(colliding_items[i])) == typeid(Robot)
                    || typeid(*(colliding_items[i])) == typeid(Zombie)
                    || typeid(*(colliding_items[i])) == typeid(WomanEnemy)){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    setPos(x()-15,y());
    if(pos().x() <= 0 ){
        scene()->removeItem(this);
        delete this;
    }
}
