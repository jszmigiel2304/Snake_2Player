#include "w_imgbutton.h"

w_imgButton::w_imgButton(QWidget *parent)
    : QWidget{parent}
{
    setMinimumHeight(90);
    setMaximumHeight(90);
    setMinimumWidth(150);
    setMaximumWidth(150);
}
