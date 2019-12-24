#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>

using namespace std;
class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    static int lifes;
    static bool new_game;
public slots:
    void spawn();
    void check();
};

#endif // PLAYER_H
