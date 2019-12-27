#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "PlayAgain.h"
#include "Score.h"
#include "Lifes.h"
#include <QTimer>
#include <QObject>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    QGraphicsPixmapItem * background;
    QGraphicsPixmapItem * game_end;
    PlayAgain* pa;
    QGraphicsScene * scene;
    Score * score;
    Player * player;
    Lifes * lifes;
    QTimer * timer;
    void game_over();
public slots:
    void reset();
};
#endif // GAME_H
