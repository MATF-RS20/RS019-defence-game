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
#include "BuildBomb.h"
#include "BuildCannon.h"
#include "BuildHole.h"
#include"BuildRemover.h"
#include"BuildWeapon.h"
#include"BuildTank.h"
#include"Tank.h"
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
    view->setFixedSize(1300,700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->showFullScreen();
    view->setMouseTracking(true);
    scene->setSceneRect(0,0,1300,700);

    // Pozadina
    QPixmap bk(":/imgs/plants-vs-zombies-background-7.jpg");
    QGraphicsPixmapItem * backround = new QGraphicsPixmapItem();
    backround->setPixmap(bk.scaled(QSize(2000,1000)));
    backround->setPos(-300,-200);
    scene->addItem(backround);

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
    box= UIButton(10,605);
    scene->addItem(box);
    box = UIButton(160,605);
    scene->addItem(box);
    box= UIButton(310,605);
    scene->addItem(box);
    box= UIButton(460,605);
    scene->addItem(box);
    box= UIButton(610,605);
    scene->addItem(box);
    box= UIButton(760,605);
    scene->addItem(box);
    // Dugme za pravljenje malih kula
    BuildSmallTower * st = new BuildSmallTower();
    // Dugme za pravljenje topova
    BuildCannon * cannon = new BuildCannon();
    scene->addItem(cannon);
    // Dugme za pravljenje bombi
    BuildBomb * bomb = new BuildBomb();
    scene->addItem(bomb);
    scene->addItem(st);
    // Dugme za pravljenje rupa
    BuildHole * hole = new BuildHole();
    scene->addItem(hole);

    // Dugme za pravljenje oruzja
    BuildWeapon * weapon = new BuildWeapon();
    scene->addItem(weapon);

    // Dugme za pravljenje brisaca
    BuildRemover * remover = new BuildRemover();
    scene->addItem(remover);

    // Dugme za tenk
    BuildTank * tank = new BuildTank();
    scene->addItem(tank);

    //Protivnici se stvaraju na nekom intervalu
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(5000);
    return a.exec();
}










