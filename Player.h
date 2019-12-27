#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>
#include "PlayAgain.h"

using namespace std;
class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    static int lifes;
    PlayAgain* pa;
public slots:
    void spawn();
};

#endif // PLAYER_H
