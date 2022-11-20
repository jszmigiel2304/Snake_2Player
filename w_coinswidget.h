#ifndef W_COINSWIDGET_H
#define W_COINSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class w_coinsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_coinsWidget(QWidget *parent = nullptr);

public slots:
    void setCoinsNumberText(qint32 coins);

private:
    QWidget iconHolder;
    QLabel coinsNumberLabel;

signals:

};

#endif // W_COINSWIDGET_H
