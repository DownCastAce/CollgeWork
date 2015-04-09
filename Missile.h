#ifndef MISSILE
#define MISSILE

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Enemy.h"
#include "Bar.h"

class Missile: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Missile(int x, int y, int missile_damage=5, QGraphicsItem * parent=0);
public slots:
    void move();
    void setOwner(QGraphicsItem * item);
    QGraphicsItem * getOwner();
private:
    QGraphicsItem * owner;
    int missile_damage;
    int enemey_health;
    void checkIfMissileLeftMap();
    void setMissileRotation(int x, int y);
    int x_moving_direction;
    int y_moving_direction;
};

#endif // MISSILE

