#ifndef C_MYINTERFACEEVENTFILTER_H
#define C_MYINTERFACEEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QWidget>
#include <QMessageBox>

class c_myInterfaceEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit c_myInterfaceEventFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:

};

#endif // C_MYINTERFACEEVENTFILTER_H
