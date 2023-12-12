#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

#include "optionswindow.h"

StartMenu::StartMenu() : QWidget() {
    layout = new QVBoxLayout(this);

    buttons.append(createButton("Spiel starten", [this]() { startGame(); }, 2, 2));
    buttons.append(createButton("Optionen", [this]() { optionsMenu(); }, 2, 2));
    buttons.append(createButton("Spiel beenden", [this]() { exitGame(); }, 2, 2));

    for (QPushButton *button : buttons) {
        layout->addWidget(button);
    }

    setLayout(layout);
    showFullScreen();
}

QPushButton* StartMenu::createButton(const QString &text, const std::function<void()> &slotFunction, int positionX, int positionY) {
    QPushButton *button = new QPushButton(text, this);
    button->setFixedSize(400, 150);
    connect(button, &QPushButton::clicked, this, slotFunction);
    return button;
}

void StartMenu::startGame() {
    QMessageBox::information(this, "Verbindung wird hergestellt", "Sie verbinden sich mit dem Server: ");   // Hier später noch Servernamen bzw. ip einblenden

    for (QPushButton *button : buttons) {
        button->hide();
        // Alternativ zum Ausblenden: delete button;
    }
}

void StartMenu::optionsMenu() {
    OptionsWindow optionsWindow;
    if (optionsWindow.createButtons("adsf", [this, &optionsWindow]() {optionsWindow.bestaetigen(); }, 2, 2)) {
        QMessageBox::information(this, "Optionen", "Optionen werden angezeigt!");

        for (QPushButton *button : buttons) {
            button->hide();
        }

        buttons.append(optionsWindow.createButtons("Einstellungen bestätigen",  [this, &optionsWindow]() {optionsWindow.bestaetigen(); }, 2, 2));

        for (QPushButton *button : buttons) {
            layout->addWidget(button);
        }
    }
}

void StartMenu::exitGame() {
    QMessageBox::information(this, "Spiel beendet", "Das Spiel wird beendet. Auf Wiedersehen!");
    qApp->quit();
}
