#ifndef W_GLJOINBUTTON_H
#define W_GLJOINBUTTON_H

#include <QPushButton>
#include <QObject>
#include <QWidget>

class w_glJoinButton : public QPushButton
{
    Q_OBJECT
public:
    w_glJoinButton(QWidget *parent = nullptr, QObject * eventFilter = nullptr);
};

#endif // W_GLJOINBUTTON_H
