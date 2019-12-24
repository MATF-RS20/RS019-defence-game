#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <vector>
#include <stdbool.h>

class Zombie: public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Zombie();
    int n = 1;
    int HP = 1;
    int k = 6;
    bool escaped = false;
   // static std::vector<class Enemy*>cord_list; // Lista (y) kordinata protivnika
public slots:
    void move();
};

#endif // ZOMBIE_H
