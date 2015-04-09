#include <QApplication>
#include "MainMenu.h"
#include "Game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu menu;

    menu.show ();
    return a.exec();
}
