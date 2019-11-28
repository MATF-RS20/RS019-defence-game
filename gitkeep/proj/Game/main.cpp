#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QApplication>
#include <QObject>
#include "Player.h"
#include "TowerSmall.h"
#include "ExitBtn.h"
#include <QPixmap>
#include "BuildSmallTower.h"
#include <iostream>
QGraphicsPixmapItem* UIButton(int x,int y){
    QPixmap img(":/imgs/blue_button06.png");
        QGraphicsPixmapItem * box = new QGraphicsPixmapItem();
        box->setPixmap(img.scaled(QSize(100,100)));
        box->setPos(x,y);
        return box;

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Pravimo scenu za crtanje objekata
    QGraphicsScene * scene = new QGraphicsScene();

    //Pravimo igraca
    Player * player = new Player();
    scene->addItem(player);

    //Prikazujemo scenu
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
    view->setFixedSize(1366,700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->showFullScreen();
     view->setMouseTracking(true);
    scene->setSceneRect(0,0,1366,700);

    // Dugme za exit
    ExitBtn * exit = new ExitBtn();
    scene->addItem(exit);
    //Panel za odabir kula (ukras, zato ne pravimo zasebnu klasu)
    QPixmap panel(":/imgs/blue_panel.png");
    QGraphicsPixmapItem * box_panel = new QGraphicsPixmapItem();
    box_panel->setPixmap(panel.scaled(QSize(1500,200)));
    box_panel->setPos(-80,600);
    scene->addItem(box_panel);

    // Okviri za kule (ukras, zato ne pravimo zasebnu klasu vec samo fju za iscrtavanje)
    // shift za 150px
    QGraphicsPixmapItem * box ;
    box= UIButton(10,625);
    scene->addItem(box);
    box = UIButton(160,625);
    scene->addItem(box);
    box= UIButton(310,625);
    scene->addItem(box);
    box= UIButton(460,625);
    scene->addItem(box);
    box= UIButton(610,625);
    scene->addItem(box);
    box= UIButton(760,625);
    scene->addItem(box);
    // Dugme za pravljenje malih kula
    BuildSmallTower * st = new BuildSmallTower();
    scene->addItem(st);


    //Protivnici se stvaraju na nekom intervalu
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(5000);
    return a.exec();
}









