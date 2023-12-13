#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

class StartMenu : public QWidget {
    Q_OBJECT

public:
    StartMenu();

private:
    void startGame();
    void optionsMenu();
    void exitGame();
    void bestaetigeExit();
    QPushButton* createButton(const QString &text, const std::function<void()> &slotFunction, int positionX, int positionY);

    QVBoxLayout *layout;
    QList<QPushButton*> buttons;
};

#endif // STARTMENU_H

