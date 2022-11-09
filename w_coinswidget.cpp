#include "w_coinswidget.h"

w_coinsWidget::w_coinsWidget(QWidget *parent)
    : QWidget{parent}
{
    this->resize(40,100);

    iconHolder.setObjectName("coinsIcon");
    coinsNumberLabel.setObjectName("coinsCounter");

    iconHolder.setGeometry(0,0,40,40);
    coinsNumberLabel.setGeometry(40,0,60,40);

    iconHolder.setParent(this);
    coinsNumberLabel.setParent(this);

    coinsNumberLabel.setAlignment(Qt::AlignCenter);
    coinsNumberLabel.setText("0000");
}
