#include "w_lblineedit.h"

w_lbLineEdit::w_lbLineEdit(QWidget *parent, QObject * eventFilter)
    : QLineEdit{parent}
{
    if(eventFilter)
        installEventFilter(eventFilter);

    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QLineEdit { "
                  "background-color: transparent;"
                  "border: 0px;"
                  "margin: 0px;"
                  "color: white;"
                  "font: 20pt;"
                  "font-weight: bold;}");
}

w_lbLineEdit::~w_lbLineEdit()
{

}
