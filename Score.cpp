#include "Score.h"
#include <QFont>
#include <fstream>
#include <iostream>

using namespace std;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;
    setPlainText (QString("Score: ") + QString::number(score));
    setDefaultTextColor (Qt::green);
    setFont (QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText (QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}

void Score::decrease(){
    score--;
    setPlainText (QString("Score: ") + QString::number(score));
}

int Score::getHighScore(){
    int fileHighScore;
    ifstream highScore;
    highScore.open ("High_Score.txt");

    if(!highScore.is_open ()){
        return 0;
    }
    highScore >> fileHighScore;
    highScore.close ();

    return fileHighScore;
}
