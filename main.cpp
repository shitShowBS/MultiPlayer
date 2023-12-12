#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    StartMenu startMenu;
    startMenu.setWindowTitle("Spiel Startmenü");
    startMenu.show();

    return app.exec();
}
