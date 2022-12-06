#include "w_lbeditbutton.h"

w_lbEditButton::w_lbEditButton(QWidget *parent, QObject * eventFilter)
    : QPushButton{parent}
{
    if(eventFilter)
        installEventFilter(eventFilter);

    setFlat(true);
    setMinimumSize(50,50);
    setMaximumSize(50,50);
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QPushButton { "
                  "background-color: transparent;"
                              "background-image: url(:/graphs/line_edit_50x50.png);"
                              "border-color: rgba(128,128,128,1);"
                              "border-style: solid;"
                              "border-top-width: 0px;"
                              "border-left-width: 0px;"
                              "border-right-width: 0px;"
                              "border-bottom-width: 0px;}"
                          "QPushButton:hover {"
                  "background-color: transparent;"
                                "background-image: url(:/graphs/line_edit_50x50.png);"
                                "border-color: rgba(128,128,128,1);"
                                "border-style: solid;"
                              "border-top-width: 2px;"
                              "border-left-width: 2px;"
                              "border-right-width: 2px;"
                              "border-bottom-width: 2px;}");



}
