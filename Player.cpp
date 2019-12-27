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
#include "Game.h"
#include <QDebug>
#include <QTimer>
#include <QPainter>

extern Game * game;
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

}




