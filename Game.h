#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "PlayAgain.h"
#include "Score.h"
#include "Lifes.h"
#include "Play.h"
#include <QTimer>
#include <QObject>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    QGraphicsPixmapItem * game_end;
    Play* play;
    PlayAgain* pa;
    QGraphicsScene * scene;
    Score * score;
    Player * player;
    Lifes * lifes;
    QTimer * timer;
    bool started=false;
    bool lost=false;
    void game_over();
    void begin();
public slots:
    void reset();
};
#endif // GAME_H
