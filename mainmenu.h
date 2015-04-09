#ifndef MAINMENU
#define MAINMENU

#include <QWidget>

class MainMenu: public QWidget {
    Q_OBJECT
public:
    MainMenu(QWidget * parent=0);
public slots:
    void play();
    void exit();
};

#endif // MAINMENU

