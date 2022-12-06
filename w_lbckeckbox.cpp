#include "w_lbckeckbox.h"

w_lbCkeckBox::w_lbCkeckBox(QWidget *parent, QObject * eventFilter)
    : QCheckBox{parent}
{
    if(eventFilter)
        installEventFilter(eventFilter);

    setMinimumSize(50,50);
    setMaximumSize(50,50);
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QCheckBox { "
                  "background-color: transparent;"
                  "border-color: rgba(128,128,128,1);"
                  "border-style: solid;"
                  "border-width: 0px;}"
                  "QCheckBox:hover {"
                  "background-color: transparent;"
                  "border-color: rgba(128,128,128,1);"
                  "border-style: solid;"
                  "border-width: 2px;}"
                  "QCheckBox::indicator { "
                  "width: 45px;"
                  "height: 45px;}"
                  "QCheckBox::indicator:unchecked { "
                  "image: url(:/graphs/not_check_icon_red_50x50.png);}"
                  "QCheckBox::indicator:checked { "
                  "image: url(:/graphs/check_icon_green_50x50.png);}");

}
