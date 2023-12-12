#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

#ifndef STARTMENU_H
#define STARTMENU_H

class StartMenu : public QWidget
{
public:
    StartMenu();

private slots:
    void startGame();
    void optionsMenu();
    void exitGame();
};

#endif // STARTMENU_H
