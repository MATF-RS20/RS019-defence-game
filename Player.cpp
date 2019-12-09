#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Enemy.h"
#include "Robot.h"
#include "WomanEnemy.h"
#include <QDebug>


void Player::spawn(){
    // Pravimo protivnike
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    Robot * robot = new Robot();
    scene()->addItem(robot);
    WomanEnemy * we = new WomanEnemy();
    scene()->addItem(we);
}
