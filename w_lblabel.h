#ifndef W_LBLABEL_H
#define W_LBLABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>

class w_lbLabel : public QLabel
{
    Q_OBJECT
public:
    w_lbLabel(QWidget *parent = nullptr, QObject * eventFilter = nullptr);
    ~w_lbLabel();
};

#endif // W_LBLABEL_H
