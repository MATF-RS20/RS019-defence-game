#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include "TowerSmallBullet.h"
#include <QTimer>
#include "Enemy.h"
#include "Robot.h"
#include "WomanEnemy.h"
#include "Zombie.h"
TowerSmallBullet::TowerSmallBullet(int x,int y):QObject(),QGraphicsPixmapItem(){
    QPixmap img(":/imgs/shotThin.png");
    setPixmap(img.scaled(QSize(40,10)));
    setPos(x+50,y+80);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_bullet()));
    timer->start(100);

}

void TowerSmallBullet::move_bullet(){
    // COALISION DETECTION : preuzeto sa STACKOVERFLOW
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy) || typeid(*(colliding_items[i])) == typeid(WomanEnemy) || typeid(*(colliding_items[i])) == typeid(Robot)){
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
