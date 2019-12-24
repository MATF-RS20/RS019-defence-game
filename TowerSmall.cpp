#include "TowerSmall.h"
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QTimer>
#include <TowerSmallBullet.h>
#include "Enemy.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
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
    // Na odredjenom vremenskom intervalu kula puca
   TowerSmallBullet * sb = new TowerSmallBullet(x(),y());
    scene()->addItem(sb);

}
