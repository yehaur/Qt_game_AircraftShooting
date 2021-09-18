#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include "Bullet.h"
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class Player: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem* parent=0);
    void keyPressEvent (QKeyEvent* event);
public slots:
    void spawn();
private:
    QMediaPlayer* bulletsound;
};

#endif // PLAYER_H
