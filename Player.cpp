#include "Player.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSize>
#include <QTimer>
#include <QKeyEvent>
#include "PlayAgain.h"
#include "Enemy.h"
#include "WomanEnemy.h"
#include "Zombie.h"
#include "Robot.h"
#include <QDebug>
#include <QTimer>
#include <QPainter>

bool Player::new_game=false;
void Player::spawn(){

    // Pravimo protivnike
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    // Pravimo robota
    Robot * robot = new Robot();
    scene()->addItem(robot);
    // Pravimo neprijatelja
    WomanEnemy * woman = new WomanEnemy();
    scene()->addItem(woman);

    Zombie * zombie = new Zombie();
    scene()->addItem(zombie);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check()));
    timer->start(100);
}

void Player::check(){

    if(this->lifes <=0){

        QPixmap black(":/imgs/black3.png");
        QGraphicsPixmapItem * background = new QGraphicsPixmapItem();

        background->setPixmap(black.scaled(QSize(1366,700)));
        background->setPos(0,0);
        scene()->addItem(background);

        QPixmap end(":/imgs/game_over.png");
        QGraphicsPixmapItem * game_over = new QGraphicsPixmapItem();
        game_over->setPixmap(end.scaled(QSize(600,100)));
        game_over->setPos(350,200);
        scene()->addItem(game_over);

        PlayAgain * play_again = new PlayAgain();
        scene()->addItem(play_again);

        if(play_again->pressed){

            new_game=true;
            scene()->removeItem(background);
            delete background;
            scene()->removeItem(game_over);
            delete game_over;
            scene()->removeItem(play_again);
            delete play_again;
          /*  QList<QGraphicsItem *> colliding_items = collidingItems();
                for (int i = 0, n = colliding_items.size(); i < n; ++i){
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                }*/
        }
    }
}
