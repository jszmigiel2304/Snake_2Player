#ifndef W_SHOPITEMWIDGET_H
#define W_SHOPITEMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class w_shopItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_shopItemWidget(QWidget *parent = nullptr);

private:
    QWidget iconHolder;
    QLabel itemPriceLabel;

signals:

};

#endif // W_SHOPITEMWIDGET_H
