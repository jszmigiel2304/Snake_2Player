#include "w_speedupcounterwidget.h"

w_speedUpCounterWidget::w_speedUpCounterWidget(QWidget *parent)
    : QWidget{parent}
{
    this->resize(40,100);

    iconHolder.setObjectName("speedUpIcon");
    counterLabel.setObjectName("speedUpCounter");
    speedLvlLabel.setObjectName("speedUpCounter");

    iconHolder.setGeometry(0,0,40,40);
    counterLabel.setGeometry(40,0,60,40);
    speedLvlLabel.setGeometry(100,0,60,40);

    iconHolder.setParent(this);
    counterLabel.setParent(this);
    speedLvlLabel.setParent(this);

    counterLabel.setAlignment(Qt::AlignCenter);
    counterLabel.setText("000");
    speedLvlLabel.setText("l. 1");
}

void w_speedUpCounterWidget::setLabelText(int time)
{
    if(time == 0)
        counterLabel.setText("000");
    else
        counterLabel.setText( QString("%1").arg(time / 1000) );
}

void w_speedUpCounterWidget::setLevelLabelText(int level)
{
    if(level > game::maxSpeedUpLevel)
        speedLvlLabel.setText(QString("lvl. %1").arg(game::maxSpeedUpLevel));
    else
        speedLvlLabel.setText(QString("lvl. %1").arg(level));
}
