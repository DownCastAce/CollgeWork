#ifndef GAME
#define GAME

#include <QBrush>
#include <QImage>
#include <QGraphicsView>
#include "Player.h"
#include "score.h"

class Game: public QGraphicsView{
public:
    //Various functions
    Game(QWidget *parent=0);

    //attributes of game
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    int fps;
};

#endif // GAME

