#ifndef W_SPEEDUPCOUNTERWIDGET_H
#define W_SPEEDUPCOUNTERWIDGET_H

#include "_myData.h"

#include <QObject>
#include <QWidget>
#include <QLabel>

class w_speedUpCounterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_speedUpCounterWidget(QWidget *parent = nullptr);

    void setLabelText(int time);
    void setLevelLabelText(int level);

private:
    QWidget iconHolder;
    QLabel counterLabel;
    QLabel speedLvlLabel;

signals:

};

#endif // W_SPEEDUPCOUNTERWIDGET_H
