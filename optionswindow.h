#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include<QPushButton>

class OptionsWindow : public QWidget
{
    Q_OBJECT

public:
    OptionsWindow();
    void bestaetigen();
    QPushButton* createButtons(const QString &text, const std::function<void()> &slotFunction, int positionX, int positionY);
private slots:
    void onButtonClicked();

private:
};

#endif // OPTIONSWINDOW_H
