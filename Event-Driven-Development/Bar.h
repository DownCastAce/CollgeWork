#ifndef BAR
#define BAR

#include <QGraphicsRectItem>

class Bar: public QGraphicsRectItem{
public:
    Bar(QGraphicsItem * parent=0);
    int getCurrentVal();

    void updateBar();
    void setCurrentVal(int v);
    void setMaxVal(int v);
    void increment(int amount);
    void decrement(int amount);

private:
    int max_val;
    int current_val;
};

#endif // BAR

