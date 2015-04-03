#ifndef PLAYER
#define PLAYER

#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "Bar.h"

class Player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player();
    void keyPressEvent (QKeyEvent *event);
    void keyReleaseEvent (QKeyEvent *event);
    Bar * health_bar;
public slots:
    void timerEvent();
    void decreaseHealth(int damage);
    void spawn();
private:
    int health;
    int plane_rotation;
    bool is_moving_left;
    bool is_moving_right;
    bool is_moving_up;
    bool is_moving_down;
    void setPlayerRotation();
    void createMissile();
};

#endif // PLAYER

