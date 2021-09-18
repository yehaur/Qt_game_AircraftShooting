#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsView>
#include "Enemy.h"

Player::Player(QGraphicsItem* parent): QGraphicsPixmapItem(parent){
    // bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/qt-bullet.mp3"));

    // set graphic
    setPixmap(QPixmap(":/images/qt-image-player.jpeg"));
}

void Player::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Left){
        if(pos().x() >= 10)
            setPos(x()-10, y());
    }else if(event->key() == Qt::Key_Right){
        if(pos().x()+100 <= 800)
        setPos(x()+10, y());
    }/*else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }*/
    else if(event->key() == Qt::Key_Space){
        // create a bullet
        Bullet* bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);

        // play bulletsound
        if(bulletsound->state() == QMediaPlayer::PlayingState)
            bulletsound->setPosition(0);
        else if(bulletsound->state() == QMediaPlayer::StoppedState)
            bulletsound->play();
    }
}

void Player::spawn(){
    // create enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
