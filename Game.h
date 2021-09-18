#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include <QWidget>
#include "Score.h"
#include "Health.h"

class Game{
public:
    Game(QWidget* parent=0);

    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;
};


#endif // GAME_H
