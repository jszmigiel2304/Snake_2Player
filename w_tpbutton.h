#ifndef W_TPBUTTON_H
#define W_TPBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class w_tpButton : public QPushButton       /// top panel button
{
    Q_OBJECT

public:
    explicit w_tpButton(QWidget *parent = nullptr, QObject * eventFilter = nullptr);
    void setTextSizeCheck(const QString &text);

private:

signals:

};

#endif // W_TPBUTTON_H
