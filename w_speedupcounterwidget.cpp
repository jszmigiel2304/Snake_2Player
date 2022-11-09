#include "w_speedupcounterwidget.h"

w_speedUpCounterWidget::w_speedUpCounterWidget(QWidget *parent)
    : QWidget{parent}
{
    this->resize(40,100);

    iconHolder.setObjectName("speedUpIcon");
    counterLabel.setObjectName("speedUpCounter");

    iconHolder.setGeometry(0,0,40,40);
    counterLabel.setGeometry(40,0,60,40);

    iconHolder.setParent(this);
    counterLabel.setParent(this);

    counterLabel.setAlignment(Qt::AlignCenter);
    counterLabel.setText("000");
}
