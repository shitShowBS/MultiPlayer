#include <optionswindow.h>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>

OptionsWindow::OptionsWindow() {
    createButtons("adsf",  [this]() { bestaetigen(); }, 2, 2);
}

QPushButton* OptionsWindow::createButtons(const QString &text, const std::function<void()> &slotFunction, int positionX, int positionY) {
    QPushButton *button = new QPushButton(text, this);
    button->setFixedSize(400, 150);
    connect(button, &QPushButton::clicked, this, slotFunction);
    return button;
}

void OptionsWindow::bestaetigen() {
    std::cout << "alo" << std::endl;
}


void OptionsWindow::onButtonClicked() {
    std::cout <<"Moin" << std::endl;
}
