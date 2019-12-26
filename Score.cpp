#include "Score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 10;

    // draw the text
    setPos(85,15);
    setPlainText( QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",25));
}

void Score::prints(){
    setPlainText( QString::number(score)); // Score: 1
}

