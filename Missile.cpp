#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo.h>

#include "Game.h"
#include "Missile.h"

extern Game * game;

Missile::Missile(int x, int y, int missile_damage, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    this->missile_damage = missile_damage;

    setPixmap (QPixmap(":/images/missile.png"));
    setMissileRotation (x, y);

    x_moving_direction = x;
    y_moving_direction = y;

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(1000/game->fps);
}

void Missile::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n; i++) {

        Enemy * attacked_object = dynamic_cast<Enemy *>(colliding_items[i]);
        if(attacked_object != NULL && attacked_object != owner) {


            attacked_object->decreaseHealth (missile_damage);
            scene()->removeItem(this);

            //delete both items from heap
            delete this;
            break;
        }

        if(typeid(*colliding_items[i]) == typeid(Player) && colliding_items[i] != owner) {
            Player * p = static_cast<Player *>(colliding_items[i]);
            p->decreaseHealth (missile_damage);
            game->scene->removeItem (this);
            delete this;
            break;
        }
    }

    setPos(x()+x_moving_direction, y()+y_moving_direction);
    checkIfMissileLeftMap();
}

void Missile::setOwner(QGraphicsItem *item){
    owner = item;
}

QGraphicsItem *Missile::getOwner(){
    return owner;
}

void Missile::checkIfMissileLeftMap() {
    if(pos().y ()< -16 || pos().y() > 900 || pos().x() > 1600 || pos().x() < -32) {
        scene()->removeItem(this);
        delete this;
    }
}

void Missile::setMissileRotation(int x, int y) {
    setTransformOriginPoint (16,8);
    int missile_rotation = 270;
    //Down Right
    if (x >= 4 && y >= 4)
        missile_rotation = 45;
    //Up Right
    else if (x >= 4 && y <= -4)
        missile_rotation = 315;
    //Down Left
    else if (x <= -4 && y >= 4)
        missile_rotation = 135;
    //Up Left
    else if (x <= -4 && y <= -4)
        missile_rotation = 225;
    //Right
    else if(x >= 5 && y == 0)
        missile_rotation = 0;
    //Left
    else if ( x <= -5 && y == 0)
        missile_rotation = 180;
    //Down
    else if (y >= 5 && x == 0)
        missile_rotation = 90;
    //Up
    else
        missile_rotation = 270;
    setRotation (missile_rotation);
}
