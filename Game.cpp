#include "Game.h"
#include <QGraphicsScene>
#include <QMediaPlaylist>
#include <QIcon>



Game::Game(QWidget *parent) {

    fps =30;
    //Create the scene for the game
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1600,900);
    setBackgroundBrush (QBrush(QImage(":/images/background.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setMinimumSize (1600, 900);
    setWindowTitle ("Star Fighter");
    setWindowIcon (QIcon(":/images/images.png"));

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



    music = new QMediaPlayer(this);
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/background.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music->setPlaylist (playlist);
    playlist->setCurrentIndex(0);
    music->setVolume (25);
    music->play ();

    show();
}

void Game::mousePressEvent(QMouseEvent *event){
    //This method just stops the mouse from causing the game to lose focus on the player
}

void Game::mouseDoubleClickEvent(QMouseEvent *event){
    //This method just stops the mouse from causing the game to lose focus on the player
}

void Game::resetFocus(){
    player->setFocus ();
}
