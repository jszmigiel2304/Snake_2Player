#ifndef W_SPEEDUPCOUNTERWIDGET_H
#define W_SPEEDUPCOUNTERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class w_speedUpCounterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_speedUpCounterWidget(QWidget *parent = nullptr);

private:
    QWidget iconHolder;
    QLabel counterLabel;

signals:

};

#endif // W_SPEEDUPCOUNTERWIDGET_H
