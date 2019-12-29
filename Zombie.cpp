#include "Zombie.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <vector>
#include <ctime>
#include "TowerSmallBullet.h"
#include "CannonBullet.h"
#include "Weapon.h"
#include "WeaponBullets.h"
#include "Bomb.h"
#include "TankRocket.h"
#include "Player.h"
#include "Hole.h"
#include "Weapon.h"
#include "Game.h"
//std::vector<class Enemy*> Enemy::cord_list;
extern Game* game;
Zombie::Zombie():QObject(),  QGraphicsPixmapItem()
{

    int random_n = rand() % 500; // sa %500 ogranicavamo da se protivnik ne pravi na Y>500
    setPos(-70,random_n);
    //Crtamo protivnika
    QPixmap img(":/imgs/character_femaleAdventurer_walk0.png");
    setPixmap(img.scaled(QSize(75,75)));

    // Timer koji pomera protivnika
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(200);
}

void Zombie::move(){
    //HIT DETECTION preuzet sa Stackoverflow-a

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(TowerSmallBullet)
                || typeid(*(colliding_items[i])) == typeid(CannonBullet1)
                || typeid(*(colliding_items[i])) == typeid(CannonBullet2)
                || typeid(*(colliding_items[i])) == typeid(WeaponBullet1)
                || typeid(*(colliding_items[i])) == typeid(WeaponBullet2)
                || typeid(*(colliding_items[i])) == typeid(WeaponBullet3)
                ){
            this->HP -=1;
            if(this->HP==0){
                game->score->score+=cost;
                game->score->prints();
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
            if (typeid(*(colliding_items[i])) == typeid(Bomb)
                    || typeid(*(colliding_items[i])) == typeid(TankRocket)){
                game->score->score+=cost;
                game->score->prints();
                scene()->removeItem(this);
                delete this;
                return;
            }

            if (typeid(*(colliding_items[i])) == typeid(Hole)){
                k=2;
            }

        }
    setPos(x()+k,y());
    if(pos().x() > 800 && !(this->escaped)){
        Player::lifes-=1;
        this->escaped = true;
        if(Player::lifes<=0){
            game->game_over();
        }
    }
    //Sa svakim otkucajem tajmere protivnik se pomera i menja se slika hoda
    if (this->n == 1){
        QPixmap img(":/imgs/zombie_1.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=2;
    }else {
        QPixmap img(":/imgs/zombie_2.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=1;
    }
}
