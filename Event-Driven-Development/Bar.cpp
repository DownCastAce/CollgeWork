#include "Bar.h"
#include <QBrush>

Bar::Bar(QGraphicsItem *parent): QGraphicsRectItem(parent){
    max_val = 1;
    current_val = 1;
    setRect(parent->pos().x(),parent->pos().y(),80,5);
    setBrush(QBrush(Qt::red));
    setRotation(90);
}
void Bar::updateBar(){
    double fill_fraction = double(current_val) / max_val;
    setRect(rect().x(),rect().y(),fill_fraction * 80,5);
}
int Bar::getCurrentVal(){
    return current_val;
}
void Bar::setCurrentVal(int v){
    current_val = v;
}
void Bar::setMaxVal(int v){
    max_val = v;
}
void Bar::increment(int amount){
    current_val = current_val + amount;
    updateBar();
}
void Bar::decrement(int amount){
    current_val = current_val - amount;
    updateBar();
}
