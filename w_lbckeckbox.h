#ifndef W_LBCKECKBOX_H
#define W_LBCKECKBOX_H

#include <QCheckBox>
#include <QObject>
#include <QWidget>

class w_lbCkeckBox : public QCheckBox
{
    Q_OBJECT
public:
    w_lbCkeckBox(QWidget *parent = nullptr, QObject * eventFilter = nullptr);
};

#endif // W_LBCKECKBOX_H
