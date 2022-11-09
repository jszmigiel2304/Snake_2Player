#ifndef C_MYEVENTFILTER_H
#define C_MYEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QWidget>

class c_myEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit c_myEventFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:

};

#endif // C_MYEVENTFILTER_H
