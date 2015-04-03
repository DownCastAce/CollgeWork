#include "Player.h"
#include "Game.h"
#include "Missile.h"
#include "Enemy.h"
#include <QDebug>

extern Game * game;

Player::Player() {

    setPixmap (QPixmap(":/images/player.png"));
    setTransformOriginPoint (47.5, 62);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timerEvent()));
    timer->start(4);

    health = 20;
    health_bar = new Bar(this);
    health_bar->setMaxVal (20);
    health_bar->setCurrentVal (20);

    is_moving_up = false;
    is_moving_down = false;
    is_moving_left = false;
    is_moving_right = false;
}

void Player::timerEvent() {
    if (is_moving_left && (x() >= 0)) {
        setPos(x()-1,y());
    }
    if (is_moving_right && ((x()+95) < 1600)) {
        setPos(x()+1,y());
    }
    if (is_moving_up && (y() >= 0)) {
        setPos(x(),y()-1);
    }
    if (is_moving_down && ((y()+124) < 900)) {
        setPos(x(),y()+1);
    }
    setPlayerRotation();
}

void Player::decreaseHealth(int damage) {
    health = health - damage;
    health_bar->decrement (damage);
    health_bar->updateBar ();

    if (health <= 0) {
        qDebug() << "Game Over";
        game->close ();
    }
}

void Player::setPlayerRotation(){
    if (is_moving_up && is_moving_right) {
        plane_rotation = 45;
    } else if (is_moving_down && is_moving_right) {
       plane_rotation = 135;
    } else if (is_moving_down && is_moving_left) {
        plane_rotation = 225;
    } else if (is_moving_up && is_moving_left) {
        plane_rotation = 315;
    } else if (is_moving_right) {
        plane_rotation = 90;
    } else if(is_moving_left) {
        plane_rotation = 270;
    } else if(is_moving_down) {
        plane_rotation = 180;
    } else if (is_moving_up){
        plane_rotation = 0;
    } setRotation (plane_rotation);
}

void Player::createMissile(){
    int x_direction = 0;
    int y_direction = -5;
    int x_missile_location = 0;
    int y_missile_location = 0;
    if (is_moving_up && is_moving_right) {
        x_direction = 4; y_direction = -4;
    } else if (is_moving_down && is_moving_right) {
        x_direction = 4; y_direction = 4;
    } else if (is_moving_down && is_moving_left) {
        x_direction = -4; y_direction = 4;
    } else if (is_moving_up && is_moving_left) {
        x_direction = -4; y_direction = -4;
    } else if (is_moving_right) {
        x_direction = 5; y_direction = 0;
    } else if(is_moving_left) {
        x_direction = -5; y_direction = 0;
    } else if(is_moving_down) {
        x_direction = 0; y_direction = 5;
    } else if (is_moving_up){
        x_direction = 0; y_direction = -5;
    }
    Missile * missile = new Missile(x_direction, y_direction);
    missile->setOwner (this);
    missile->setPos (x(), y());
    scene()->addItem (missile);
}

void Player::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_A : this->is_moving_left = true; break;
        case Qt::Key_D : this->is_moving_right = true; break;
        case Qt::Key_W: this->is_moving_up = true; break;
        case Qt::Key_S : this->is_moving_down = true; break;
    }
    if(event->key () == Qt::Key_Space) {
        createMissile ();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_A : this->is_moving_left = false; break;
        case Qt::Key_D : this->is_moving_right = false; break;
        case Qt::Key_W : this->is_moving_up = false; break;
        case Qt::Key_S : this->is_moving_down = false; break;
    }
}

void Player::spawn(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
