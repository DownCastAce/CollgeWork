#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include "Missile.h"
#include <QDebug>
#include <typeinfo.h>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent) {

    enemy_health = 20;
    enemy_health_bar = new Bar(this);
    enemy_health_bar->setMaxVal (20);
    enemy_health_bar->setCurrentVal (20);

    int random_number = rand() % 1500;
    setPos(random_number,0);

    setPixmap (QPixmap(":/images/normalEnemy.png"));
    setTransformOriginPoint (64,64);
    setRotation (180);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    QTimer * shot_timer = new QTimer();
    connect(shot_timer,SIGNAL(timeout()),this,SLOT(shoot()));
    shot_timer->start(2500);
}

Enemy::~Enemy () {
    //qDebug() << "Enemy plane destroyed";
    if (game->score->getScore ()< 0) {
        game->close ();
    }
}

void Enemy::move() {
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n; i++) {
        if(typeid(*(colliding_items[i])) == typeid(Player)) {

            Player * thePlayer = dynamic_cast<Player *>(colliding_items[i]);
            thePlayer->decreaseHealth (5);
            scene()->removeItem(this);

            //delete item from heap
            delete this;
            return;
        }
    }
    setPos(x(),y()+5);
    if(pos().y() > 900){
        scene()->removeItem(this);
        game->score->decrease ();
        delete this;
    }
}

void Enemy::shoot(){
    Missile * missile = new Missile(0, 7, 5);
    missile->setPos (x()+32, y()+100);
    missile->setOwner (this);
    scene()->addItem (missile);
}

void Enemy::decreaseHealth(int damage){
    enemy_health = enemy_health - damage;
    enemy_health_bar->decrement (damage);
    enemy_health_bar->updateBar ();

    if (enemy_health <= 0) {
        game->scene->removeItem (this);
        delete this;
        game->score->increase();
    }
}
