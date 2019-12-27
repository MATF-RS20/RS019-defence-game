#include "Enemy.h"
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
#include "Bomb.h"
#include "Weapon.h"
#include "WeaponBullets.h"
#include "Player.h"
#include "Hole.h"
#include "Score.h"
#include "TankRocket.h"
#include "Game.h"
//std::vector<class Enemy*> Enemy::cord_list;
extern Game * game;
int Player::lifes = 3;
Enemy::Enemy():QObject(),  QGraphicsPixmapItem()
{

    int random_n = rand() % 500; // sa %500 ogranicavamo da se protivnik ne pravi na Y>500
    setPos(-70,random_n);//-10
    //Crtamo protivnika
    QPixmap img(":/imgs/character_zombie_walk1.png");
    setPixmap(img.scaled(QSize(80,80)));

    //Timer koji pomera protivnika
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(200);

}


void Enemy::move(){
    //HIT DETECTION preuzet sa Stackoverflow-a

    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(TowerSmallBullet)
                    || typeid(*(colliding_items[i])) == typeid(CannonBullet1)
                    || typeid(*(colliding_items[i])) == typeid(CannonBullet2)
                    || typeid(*(colliding_items[i])) == typeid(WeaponBullet1)
                    || typeid(*(colliding_items[i])) == typeid(WeaponBullet2)
                    || typeid(*(colliding_items[i])) == typeid(WeaponBullet3)){
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
        QPixmap img(":/imgs/character_zombie_walk2.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=2;
    }else if(this->n==2){
        QPixmap img(":/imgs/character_zombie_walk3.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=3;
    }else if(this->n==3){
        QPixmap img(":/imgs/character_zombie_walk1.png");
        setPixmap(img.scaled(QSize(80,80)));
        this->n=1;
    }

}



