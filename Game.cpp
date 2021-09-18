#include "Game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>

Game::Game(QWidget* parent){
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/qt-image-bg.jpeg")));

    // make the newly created scene the scene to visualize
    // add a view
    QGraphicsView* view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->setFixedSize(800,600);

    // create an item to put into the scene
    Player* player =  new Player();
    //player->setRect(0,0,100,100);
    player->setPos(400,500);
    // make item focused
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the item to the scene
    scene->addItem(player);

    //create the score
    score = new Score();
    scene->addItem(score);

    //create health
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    //add player to scene
    scene->addItem(player);

    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // play background music
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/qt-game_background.wav"));
    music->play();

    view->show();
}
