#include "w_tpbutton.h"

w_tpButton::w_tpButton(QWidget *parent, QObject * eventFilter)
    : QPushButton{parent}
{
    if(eventFilter)
        installEventFilter(eventFilter);

    setFlat(true);
    setMinimumSize(150,90);
    setMaximumSize(150,90);
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QPushButton { "
                  "background-color: transparent;"
                  "border: 0px;"
                  "margin: 0px;"
                  "color: white;"
                  "font: 30pt;"
                  "font-weight: bold;"
                  "background-image: url(:/graphs/button_bg_150w.png);}"
                  "QPushButton:hover { "
                  "background-color: transparent;"
                  "background-image: url(:/graphs/button_bg_mouse_on_150w.png);}");

}

void w_tpButton::setTextSizeCheck(const QString &text)
{
    if(text.size() > 5)
        setStyleSheet("QPushButton { "
                      "background-color: transparent;"
                      "border: 0px;"
                      "margin: 0px;"
                      "color: white;"
                      "font: 20pt;"
                      "font-weight: bold;"
                      "background-image: url(:/graphs/button_bg_150w.png);}"
                      "QPushButton:hover { "
                      "background-color: transparent;"
                      "background-image: url(:/graphs/button_bg_mouse_on_150w.png);}");

    setText(text);
}
