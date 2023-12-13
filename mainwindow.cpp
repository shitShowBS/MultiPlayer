#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDialog>
#include <QLabel>

#include "optionswindow.h"

//Ruft die Factory für die Buttons auf und gibt die Parameter mit
//Zuständig für den Aufbau der Startseite
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

//Factory für die Buttons -> Anhand der Parameter werden eigenständige Buttons erstellt
QPushButton* StartMenu::createButton(const QString &text, const std::function<void()> &slotFunction, int positionX, int positionY) {
    QPushButton *button = new QPushButton(text, this);
    button->setFixedSize(400, 150);
    connect(button, &QPushButton::clicked, this, slotFunction);
    return button;
}

//Funktion für den Button welcher für den Start des Spieles zuständig ist
//Stellt automatisch eine Verbindung zu dem Server her welcher in den Optionen festgelegt wurde
void StartMenu::startGame() {
    QMessageBox::information(this, "Verbindung wird hergestellt", "Sie verbinden sich mit dem Server: ");   // Hier später noch Servernamen bzw. ip einblenden

    for (QPushButton *button : buttons) {
        button->hide();
        // Alternativ zum Ausblenden: delete button;
    }
}

//Entfernt alle bisher auf der Seite angezeigte Buttons und baut die Einstellungen-Seite auf
void StartMenu::optionsMenu() { //TODO evtl. noch bessere Lösung für tatsächliche Löschung der Buttons finden
    OptionsWindow optionsWindow;
    if (optionsWindow.createButtons("adsf", [&optionsWindow]() {optionsWindow.bestaetigen(); }, 2, 2)) {
        QMessageBox::information(this, "Optionen", "Optionen werden angezeigt!");

        for (QPushButton *button : buttons) {
            button->hide();
        }

        buttons.append(optionsWindow.createButtons("Einstellungen bestätigen",  [&optionsWindow]() {optionsWindow.bestaetigen(); }, 2, 2));

        for (QPushButton *button : buttons) {
            layout->addWidget(button);
        }
        layout->addWidget(optionsWindow.createLineEdit());
    }
}

//Schließt das Spiel mit einer entsprechenden Meldung
void StartMenu::exitGame() { //TODO prüfung einbauen ob der Nutzer da s Spiel wirklich beenden möchte
    QDialog *exitDialog = new QDialog(this);

    QVBoxLayout *layout = new QVBoxLayout(exitDialog);
    QLabel *label = new QLabel("Möchtest du das Spiel wirklich beenden?", exitDialog);
    QPushButton *confirmButton = new QPushButton("Ja", exitDialog);
    QPushButton *cancelButton = new QPushButton("Nein", exitDialog);

    connect(confirmButton, &QPushButton::clicked, this, &StartMenu::bestaetigeExit);
    connect(cancelButton, &QPushButton::clicked, exitDialog, &QDialog::reject);

    layout->addWidget(label);
    layout->addWidget(confirmButton);
    layout->addWidget(cancelButton);

    exitDialog->exec();
}

//Wird aufgerufen, wenn das Beenden des Programmes erwünscht war
//Beendigung wird ausgefüht
void StartMenu::bestaetigeExit() {  //evtl hier automatische Trennung von Server initialisieren
    qApp->quit();
}
