#include "w_shopitemwidget.h"

w_shopItemWidget::w_shopItemWidget(QWidget *parent)
    : QWidget{parent}
{
    this->resize(40,100);

    iconHolder.setObjectName("shopItemIcon");
    itemPriceLabel.setObjectName("itemPriceLabel");

    iconHolder.setGeometry(0,0,40,40);
    itemPriceLabel.setGeometry(40,0,60,40);

    iconHolder.setParent(this);
    itemPriceLabel.setParent(this);

    itemPriceLabel.setAlignment(Qt::AlignCenter);
    itemPriceLabel.setText("x00");
}
