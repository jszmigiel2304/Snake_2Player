#include "w_leftpanel.h"

w_leftPanel::w_leftPanel(QWidget *parent)
    : QWidget{parent}
{
    startButton = new w_imgButton(this);
    settingsButton = new w_imgButton(this);
    closeButton = new w_imgButton(this);

    startButton->resize(150,90);
    startButton->setStyleSheet("     border-width: 3px;"
                              "border-style: solid;"
                              "border-color: red;"
                              "background-color: blue;");

    settingsButton->resize(150,90);
    settingsButton->setStyleSheet("     border-width: 3px;"
                              "border-style: solid;"
                              "border-color: red;"
                              "background-color: blue;");

    closeButton->resize(150,90);
    closeButton->setStyleSheet("     border-width: 3px;"
                              "border-style: solid;"
                              "border-color: red;"
                              "background-color: blue;");


    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");
    button1->setStyleSheet("     border-width: 3px;"
                              "border-style: solid;"
                              "border-color: red;"
                              "background-color: blue;");
    button2->setStyleSheet("     border-width: 3px;"
                              "border-style: solid;"
                              "border-color: red;"
                              "background-color: blue;");
    button3->setStyleSheet("     border-width: 3px;"
                              "border-style: solid;"
                              "border-color: red;"
                              "background-color: blue;");
    button4->setStyleSheet("     border-width: 3px;"
                              "border-style: solid;"
                              "border-color: red;"
                              "background-color: blue;");
    button5->setStyleSheet("     border-width: 3px;"
                              "border-style: solid;"
                              "border-color: red;"
                              "background-color: blue;");

    layout.addWidget(button1);
    layout.addWidget(button2);
    layout.addWidget(button3);
    layout.addWidget(button4);
    layout.addWidget(button5);

    layout.addWidget(startButton);
    layout.addWidget(settingsButton);
    layout.addWidget(closeButton);


    setLayout(&layout);
}
