#include "Score.h"
#include <QFont>

Score::Score(QGraphicsTextItem* parent): QGraphicsTextItem(parent){
    // Initialize the score to 0
    score = 0;

    //draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score:
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score:
}

int Score::getSore(){
    return score;
}
