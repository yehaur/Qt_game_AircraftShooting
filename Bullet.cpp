#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <Enemy.h>
#include "Game.h"

extern Game* game;

Bullet::Bullet(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent){
    // draw bullet
    setPixmap(QPixmap(":/images/qt-image-bullet.jpeg"));
    pixmap().PdmDevicePixelRatioScaled;

    // create connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);
}

void Bullet::move(){
    // when bullet collides with enenmy both destroyed
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
           // Increase score
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(), y()-10);
    if(pos().y() + pixmap().height()< 0){
        scene()->removeItem(this);
        delete this;
    }
}
