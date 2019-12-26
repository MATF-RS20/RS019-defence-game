#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsRectItem>
#include <QObject>
#include <vector>
#include <stdbool.h>
class Enemy: public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
    int n=1;
    int HP = 2;
    int k = 3;
    int cost=1;
    bool escaped = false;
   // static std::vector<class Enemy*>cord_list; // Lista (y) kordinata protivnika
public slots:
    void move();
};

#endif // ENEMY_H
