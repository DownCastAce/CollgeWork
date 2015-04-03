#include "Game.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>



Game::Game(QWidget *parent) {

    fps =30;
    //Create the scene for the game
    scene = new QGraphicsScene(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1600,900);
    setBackgroundBrush (QBrush(QImage(":/images/background.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setFixedSize(1024,768);
    setMinimumSize (1600, 900);
    setWindowTitle ("Star Fighter");

    player = new Player();
    player->setPos(800, 450);

    player->setFlag(QGraphicsItem::ItemIsFocusable,true);
    player->setFocus();

    scene->addItem (player);

    score = new Score();
    scene->addItem (score);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer * music = new QMediaPlayer(this);
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/Goblin-Loop.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music->setPlaylist (playlist);
    playlist->setCurrentIndex(0);
    music->setVolume (50);
    music->play ();

    show();
}
