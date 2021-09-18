#include "Health.h"
#include <QFont>

Health::Health(QGraphicsTextItem* parent): QGraphicsTextItem(parent){
    // Initialize the score to 0
    health = 3;

    //draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // health:
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health:
}

int Health::getHealth(){
    return health;
}
