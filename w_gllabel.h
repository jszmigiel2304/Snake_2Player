#ifndef W_GLLABEL_H
#define W_GLLABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>

class w_glLabel : public QLabel
{
    Q_OBJECT
public:
    w_glLabel(QWidget *parent = nullptr, QObject * eventFilter = nullptr);
};

#endif // W_GLLABEL_H
