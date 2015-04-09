#ifndef SCORE
#define SCORE

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem {
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
    void decrease();
    static int getHighScore();
private:
    int score;
};

#endif // SCORE

