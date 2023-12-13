#include <optionswindow.h>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>
#include <QLineEdit>
#include <propertiescontroller.h>

OptionsWindow::OptionsWindow() {
    createButtons("adsf",  [this]() { bestaetigen(); }, 2, 2);
}

//Erstellt die nötigen Buttons für das Fenster Optionen
QPushButton* OptionsWindow::createButtons(const QString &text, const std::function<void()> &slotFunction, int positionX, int positionY) {
    QPushButton *button = new QPushButton(text, this);
    button->setFixedSize(400, 150);
    connect(button, &QPushButton::clicked, this, slotFunction);
    return button;
}

//Erstellt den LineEdit zum Eintragen der IP des Servers
QLineEdit* OptionsWindow::createLineEdit() {
    QLineEdit *lineEdit = new QLineEdit();
    return lineEdit;
}

//Zuständig für die Funktion des Buttons "Bestätigen" welcher die vorgenommen Einstellungen übernimmt
void OptionsWindow::bestaetigen() {
    std::cout << "alo" << std::endl;

        PropertiesController myProperties("../Andere Dateien/benutzereinstellungen.properties");

        myProperties.setProperty("testeinstellung", "TestServer"); //text aus lineedit
}

//Eine Testfunktion wird nicht länger benötigt ggf. entfernen
void OptionsWindow::onButtonClicked() {
    std::cout <<"Moin" << std::endl;
}
