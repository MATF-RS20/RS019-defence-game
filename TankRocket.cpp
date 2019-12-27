#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include "TankRocket.h"
#include <QTimer>
#include "Enemy.h"
#include "Robot.h"
#include "WomanEnemy.h"
#include "Zombie.h"
#include "CannonBullet.h"
TankRocket::TankRocket(int x,int y):QObject(),QGraphicsPixmapItem(){
    QPixmap img(":/imgs/rocket.png");
    setPixmap(img.scaled(QSize(40,10)));
    setPos(x-23,y+5);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_rocket()));
    timer->start(50);

}
void TankRocket::RocketExplode(){
    CannonBullet1 * cb1 = new CannonBullet1(x()-45,y());
    CannonBullet2 * cb2 = new CannonBullet2(x()-45,y());
     scene()->addItem(cb1);
     scene()->addItem(cb2);
     return;

}
void TankRocket::move_rocket(){
    // COALISION DETECTION : preuzeto sa STACKOVERFLOW
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy)
                    || typeid(*(colliding_items[i])) == typeid(WomanEnemy)
                    || typeid(*(colliding_items[i])) == typeid(Robot)
                    || typeid(*(colliding_items[i])) == typeid(Zombie)
                    ){
                RocketExplode();
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    setPos(x()-10,y());
    if(pos().x() <= 0 ){
        scene()->removeItem(this);
        delete this;
    }

}
