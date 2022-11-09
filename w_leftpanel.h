#ifndef W_LEFTPANEL_H
#define W_LEFTPANEL_H

#include "w_imgbutton.h"

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class w_leftPanel : public QWidget
{
    Q_OBJECT
public:
    explicit w_leftPanel(QWidget *parent = nullptr);

private:
    QVBoxLayout layout;

    w_imgButton *startButton;
    w_imgButton *settingsButton;
    w_imgButton *closeButton;

signals:

};

#endif // W_LEFTPANEL_H
