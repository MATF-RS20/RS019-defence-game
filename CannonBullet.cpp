#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include "CannonBullet.h"
#include <QTimer>
#include "Enemy.h"
#include "Robot.h"
#include "WomanEnemy.h"
CannonBullet1::CannonBullet1(int x,int y):QObject(),QGraphicsPixmapItem(){
    QPixmap img(":/imgs/m1.png");
    setPixmap(img.scaled(QSize(40,10)));
    setPos(x-35,y+5);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_bullet1()));
    timer->start(100);


}
CannonBullet2::CannonBullet2(int x,int y):QObject(),QGraphicsPixmapItem(){
    QPixmap img(":/imgs/m2.png");
    setPixmap(img.scaled(QSize(40,10)));
    setPos(x-35,y+5);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_bullet2()));
    timer->start(100);


}

void CannonBullet1::move_bullet1(){
    // COALISION DETECTION : preuzeto sa STACKOVERFLOW
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy) || typeid(*(colliding_items[i])) == typeid(Robot) || typeid(*(colliding_items[i])) == typeid(WomanEnemy)){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    setPos(x()-20,y()-2);
    if(pos().x() <= 0 ){
        scene()->removeItem(this);
        delete this;
    }

}
void CannonBullet2::move_bullet2(){
    // COALISION DETECTION : preuzeto sa STACKOVERFLOW
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy) || typeid(*(colliding_items[i])) == typeid(WomanEnemy) || typeid(*(colliding_items[i])) == typeid(Robot)){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    setPos(x()-20,y()+2);
    if(pos().x() <= 0 ){
        scene()->removeItem(this);
        delete this;
    }

}

