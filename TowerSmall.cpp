#include "TowerSmall.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <TowerSmallBullet.h>
#include "Enemy.h"
#include "Robot.h"
#include "Remover.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Game.h"

extern Game* game;
TowerSmall::TowerSmall(int x,int y):QObject(), QGraphicsPixmapItem()
{
    // Pravimo malu kulu na datoj lokaciji
   QPixmap img(":/imgs/towerRound_sampleF_E.png");
   setPixmap(img.scaled(QSize(200,200)));
   setPos(x,y);
   QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(fire()));
   timer->start(2000);


}

void TowerSmall::fire()
{
    if(!game->lost && !game->pause){
    // Na odredjenom vremenskom intervalu kula puca
   TowerSmallBullet * sb = new TowerSmallBullet(x(),y());
    scene()->addItem(sb);

    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Remover) ){
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
}
