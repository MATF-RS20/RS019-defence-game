#include "Robot.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <vector>
#include "TowerSmallBullet.h"
#include "CannonBullet.h"
#include "Bomb.h"
Robot::Robot():QObject(),  QGraphicsPixmapItem()
{

    //Pozicija protivnika je random
    int random_n = rand() % 500; // sa %500 ogranicavamo da se protivnik ne pravi na Y>500
    setPos(-20,random_n);
    //Crtamo protivnika
    QPixmap img(":/imgs/character_robot_walk0.png");
    setPixmap(img.scaled(QSize(80,80)));

    // Timer koji pomera protivnika
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(200);


}


void Robot::move(){
    //HIT DETECTION preuzet sa Stackoverflow-a

    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(TowerSmallBullet) || typeid(*(colliding_items[i])) == typeid(CannonBullet1) || typeid(*(colliding_items[i])) == typeid(CannonBullet2)){
                this->HP -=1;
                if(this->HP==0){
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }
            if (typeid(*(colliding_items[i])) == typeid(Bomb)){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }

    setPos(x()+8,y());

    if(pos().x() > 800 ){
        scene()->removeItem(this);
        delete this;
    }
    //Sa svakim otkucajem tajmere protivnik se pomera i menja se slika hoda
    if (this->n == 1){
        QPixmap img(":/imgs/character_robot_walk1.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=2;
    }else if(this->n==2){
        QPixmap img(":/imgs/character_robot_walk2.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=3;
    }else if(this->n==3){
        QPixmap img(":/imgs/character_robot_walk3.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=4;
    }else if (this->n == 4){
        QPixmap img(":/imgs/character_robot_walk4.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=5;
    }else if(this->n==5){
        QPixmap img(":/imgs/character_robot_walk5.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=6;
    }else if(this->n==6){
        QPixmap img(":/imgs/character_robot_walk6.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=7;
    }else if(this->n==7){
        QPixmap img(":/imgs/character_robot_walk7.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=8;
    }else if(this->n==8){
        QPixmap img(":/imgs/character_robot_walk0.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=1;
    }

}



