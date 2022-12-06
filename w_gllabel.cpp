#include "w_gllabel.h"

w_glLabel::w_glLabel(QWidget *parent, QObject * eventFilter)
    : QLabel{parent}
{
    if(eventFilter)
        installEventFilter(eventFilter);

    setMinimumHeight(50);
    setMaximumHeight(50);
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QLabel { "
                  "background-color: transparent;"
                  "border-color: rgba(128,128,128,1);"
                  "border-style: solid;"
                  "border-width: 0px;"
                  "color: rgba(128,128,128,1);"
                  "font: 12pt;}");

}
