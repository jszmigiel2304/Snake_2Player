#include "w_gljoinbutton.h"

w_glJoinButton::w_glJoinButton(QWidget *parent, QObject * eventFilter)
    : QPushButton{parent}
{
    if(eventFilter)
        installEventFilter(eventFilter);

    setFlat(true);
    setMinimumSize(100,50);
    setMaximumSize(100,50);
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QPushButton { "
                  "background-color: transparent;"
                  "border-color: rgba(128,128,128,1);"
                  "border-style: solid;"
                  "border-width: 0px;"
                  "color: rgba(128,128,128,1);"
                  "font: 12pt;}");

}
