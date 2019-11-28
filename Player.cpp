#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Enemy.h"
#include <QDebug>


void Player::spawn(){
    // Pravimo protivnike
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
