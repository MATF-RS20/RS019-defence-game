#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <vector>
#include <stdbool.h>

class Robot: public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Robot();
    int n = 1;
    int HP = 1;
    int k = 7;
    int cost=3;
    bool escaped = false;
   // static std::vector<class Enemy*>cord_list; // Lista (y) kordinata protivnika
public slots:
    void move();
};

#endif // ROBOT_H
