#ifndef GAME
#define GAME

#include <QBrush>
#include <QImage>
#include <QGraphicsView>
#include <fstream>
#include <QMediaPlayer>

#include "Player.h"
#include "Score.h"

using namespace std;

class Game: public QGraphicsView{
public:
    //Various functions
    Game(QWidget *parent=0);

    //attributes of game
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    int fps;
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent (QMouseEvent *event);
public slots:
    void resetFocus();
private:
    QMediaPlayer * music;
};

#endif // GAME

