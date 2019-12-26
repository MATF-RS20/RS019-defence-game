#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsObject>
#include <QTimer>
#include <QApplication>
#include <QObject>
#include "Player.h"
#include "TowerSmall.h"
#include "Cannon.h"
#include "Bomb.h"
#include "ExitBtn.h"
#include <QPixmap>
#include "BuildSmallTower.h"
#include "BuildCannon.h"
#include "BuildBomb.h"
#include "Weapon.h"
#include "BuildWeapon.h"
#include "Hole.h"
#include "BuildHole.h"
#include "Remover.h"
#include "Lifes.h"
#include "BuildRemover.h"
#include <iostream>
#include "PlayAgain.h"
#include"Game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game=new Game();

    return a.exec();

}








