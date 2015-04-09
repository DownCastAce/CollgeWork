#ifndef ENEMY
#define ENEMY

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "Bar.h"

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    ~Enemy();
    Bar * enemy_health_bar;

public slots:
    void move();
    void shoot();
    void decreaseHealth(int damage);
private:
    int enemy_health;
};
#endif // ENEMY

