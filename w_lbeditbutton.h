#ifndef W_LBEDITBUTTON_H
#define W_LBEDITBUTTON_H

#include <QPushButton>
#include <QObject>
#include <QWidget>

class w_lbEditButton : public QPushButton
{
    Q_OBJECT
public:
    w_lbEditButton(QWidget *parent = nullptr, QObject * eventFilter = nullptr);
};

#endif // W_LBEDITBUTTON_H
