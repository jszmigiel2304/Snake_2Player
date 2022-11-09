#include "w_shopwidget.h"

w_shopWidget::w_shopWidget(QWidget *parent)
    : QWidget{parent}
{
    w_shopItemWidget *item1 = new w_shopItemWidget();
    w_shopItemWidget *item2 = new w_shopItemWidget();
    w_shopItemWidget *item3 = new w_shopItemWidget();

    item1->setGeometry(0,0,100,40);
    item2->setGeometry(100,0,100,40);
    item3->setGeometry(200,0,100,40);

    item1->setParent(this);
    item2->setParent(this);
    item3->setParent(this);
}
