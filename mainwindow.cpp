#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>


StartMenu::StartMenu() : QWidget() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *startButton = new QPushButton("Spiel starten", this);
    startButton->setFixedSize(400, 150);
    startButton->move(100, 200);
    connect(startButton, &QPushButton::clicked, this, &StartMenu::startGame);
    layout->addWidget(startButton);

    QPushButton *optionsButton = new QPushButton("Optionen", this);
    optionsButton->setFixedSize(400, 150);
    connect(optionsButton, &QPushButton::clicked, this, &StartMenu::optionsMenu);
    layout->addWidget(optionsButton);

    QPushButton *exitButton = new QPushButton("Spiel beenden", this);
    exitButton->setFixedSize(400, 150);
    connect(exitButton, &QPushButton::clicked, this, &StartMenu::exitGame);
    layout->addWidget(exitButton);

    setLayout(layout);
    showFullScreen();
}

void StartMenu::startGame(){
    QMessageBox::information(this, "Spiel gestartet", "Das Spiel wird gestartet!");
}

void StartMenu::optionsMenu() {
    QMessageBox::information(this, "Optionen", "Optionen werden angezeigt!");
}

void StartMenu::exitGame() {
    QMessageBox::information(this, "Spiel beendet", "Das Spiel wird beendet. Auf Wiedersehen!");
    qApp->quit();
}

