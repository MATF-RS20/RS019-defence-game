#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsRectItem>
#include <QObject>
#include <vector>
#include "Player.h"

class Enemy: public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
    int n=1;
    int HP = 2;
   // static std::vector<class Enemy*>cord_list; // Lista (y) kordinata protivnika
public slots:
    void move();
};

#endif // ENEMY_H
