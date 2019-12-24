#ifndef WOMANENEMY_H
#define WOMANENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <vector>
#include <stdbool.h>

class WomanEnemy: public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    WomanEnemy();
    int n=1;
    int HP = 1;
    int k=6;
    bool escaped = false;
   // static std::vector<class Enemy*>cord_list; // Lista 󰀀 kordinata protivnika
public slots:
    void move();
};
#endif // WOMANENEMY_H
