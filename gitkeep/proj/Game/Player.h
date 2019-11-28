#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>

using namespace std;
class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    static int coins;
public slots:
    void spawn();
};

#endif // PLAYER_H
