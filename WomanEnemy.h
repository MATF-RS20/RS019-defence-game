#ifndef WOMANENEMY_H
#define WOMANENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <vector>

class WomanEnemy: public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    WomanEnemy();
    int n=1;
    int HP = 1;
    //odredjuje brzinu kretanja zene neprijatelja
    int k=6;
   // static std::vector<class Enemy*>cord_list; // Lista (y) kordinata protivnika
public slots:
    void move();
};
#endif // WOMANENEMY_H
