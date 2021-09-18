#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "Game.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent){
    //start a random position
    int random_number = arc4random() % 700;
    setPos(random_number, 0);

    setPixmap(QPixmap(":/images/qt-image-enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    // create connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    setPos(x(), y()+5);
    if(pos().y() + pixmap().height() >= 700){
        // Fail to eliminate enemy, so decrease health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
