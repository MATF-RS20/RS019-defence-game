#include "Bomb.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <QGraphicsScene>
#include "Enemy.h"
#include "Robot.h"
#include "WomanEnemy.h"
#include "Zombie.h"
#include "Remover.h"
#include "Game.h"

extern Game* game;
Bomb::Bomb(int x,int y):QObject(), QGraphicsPixmapItem()
{
    // Pravimo bombu na datoj lokaciji
   QPixmap img(":/imgs/bomb.png");
   setPixmap(img.scaled(QSize(50,50)));
   setPos(x,y);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(wait()));
   timer->start(100);
}
void Bomb::wait()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(WomanEnemy)
                || typeid(*(colliding_items[i])) == typeid(Enemy)
                || typeid(*(colliding_items[i])) == typeid(Zombie)
                || typeid(*(colliding_items[i])) == typeid(Robot)){
            QTimer * timer = new QTimer(this);
            connect(timer,SIGNAL(timeout()),this,SLOT(explosion()));
            timer->start(200);
        }
        if (typeid(*(colliding_items[i])) == typeid(Remover) ){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if(!game->pause){
        setPos(x(),y());
    }
    if(pos().x() <= 0 ){
        scene()->removeItem(this);
        delete this;
    }

}
void Bomb::explosion(){
    setPos(x(),y());

    //Sa svakim otkucajem tajmere protivnik se pomera i menja se slika hoda
    if (this->n == 1){
        QPixmap img(":/imgs/explosion1.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=2;
    }else if(this->n==2){
        QPixmap img(":/imgs/explosion2.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=3;
    }else if(this->n==3){
        QPixmap img(":/imgs/explosion3.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=4;
    }else if(this->n==4){
        QPixmap img(":/imgs/explosion4.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=5;
    }else if(this->n==5){
        QPixmap img(":/imgs/explosion5.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=6;
    }
    else if(this->n==6){
        scene()->removeItem(this);
        delete this;
        }


}
