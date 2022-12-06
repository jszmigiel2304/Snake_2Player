#include "w_lblabel.h"

w_lbLabel::w_lbLabel(QWidget *parent, QObject * eventFilter)
    : QLabel{parent}
{
    if(eventFilter)
        installEventFilter(eventFilter);

    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QLabel { "
                  "background-color: transparent;"
                  "border: 0px;"
                  "margin: 0px;"
                  "color: white;"
                  "font: 20pt;"
                  "font-weight: bold;}");

    setIndent(10);
}

w_lbLabel::~w_lbLabel()
{

}

