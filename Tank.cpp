#include "Tank.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <TankRocket.h> //TODO
#include "Enemy.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Game.h"
#include "Remover.h"

extern Game* game;

Tank::Tank(int x,int y):QObject(), QGraphicsPixmapItem()
{
    // Pravimo tenk na datoj lokaciji
   QPixmap img(":/imgs/tank.png");
   setPixmap(img.scaled(QSize(75,55)));
   setPos(x+38,y+70);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(fire()));
   timer->start(5000);


}

void Tank::fire()
{
    if(!game->lost && !game->pause){
        // Na odredjenom vremenskom intervalu tenk puca
        TankRocket * sb = new TankRocket(x(),y());
        scene()->addItem(sb);
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Remover) ){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }

}
