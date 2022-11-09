#ifndef W_SHOPWIDGET_H
#define W_SHOPWIDGET_H

#include "w_shopitemwidget.h"

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>

class w_shopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_shopWidget(QWidget *parent = nullptr);

signals:

};


#endif // W_SHOPWIDGET_H
