#include "MainMenu.h"
#include "Game.h"
#include "Score.h"

#include <QString>
#include <QLabel>
#include <QIcon>
#include <QPushButton>
#include <QVBoxLayout>

extern Game * game;

MainMenu::MainMenu(QWidget *parent){
    QLabel * title = new QLabel("<font size=20 color=green>Star Fighter</font>",this);
    QLabel * how_to = new QLabel(this);

    QPushButton * play_btn = new QPushButton("Play", this);
    QPushButton * exit_btn = new QPushButton("Exit", this);

    QString how_to_txt(QString("-move with the W, A, S and D keys<br>") + QString("-Use the spacebar to shoot<br><br>") + QString("The High Score is : ") + QString::number ((Score::getHighScore ())));

    how_to->setText(how_to_txt);
    how_to->setAlignment(Qt::AlignHCenter);
    title->setAlignment(Qt::AlignHCenter);

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(how_to);
    layout->addWidget(play_btn);
    layout->addWidget (exit_btn);

    setWindowIcon (QIcon(":/images/images.png"));
    setMinimumSize (200,150);
    setWindowTitle ("Star Fighter");
    setLayout(layout);

    connect(play_btn,SIGNAL(clicked()),this,SLOT(play()));
    connect(exit_btn, SIGNAL(clicked()),this,SLOT(exit()));
}

void MainMenu::play(){
    game = new Game();
    game->show();

    //close window
    close();
}

void MainMenu::exit(){
    close();
}
