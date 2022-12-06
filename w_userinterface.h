#ifndef W_USERINTERFACE_H
#define W_USERINTERFACE_H

#include "c_myinterfaceeventfilter.h"

#include <QObject>
#include <QWidget>
#include <QAction>

class w_UserInterface : public QWidget
{
    Q_OBJECT
public:
    w_UserInterface(QWidget *parent = nullptr);

    c_myInterfaceEventFilter *getMyEventFilter() const;

    void createInterface();

public slots:

protected:
    QWidget *topBox;
    QWidget *centralBox;
    QWidget *bottomBox;

    virtual void createTopBox() = 0;
    virtual void createCentralBox() = 0;
    virtual void createBottomBox() = 0;

private:
    c_myInterfaceEventFilter *myEventFilter;

private slots:

signals:

};

#endif // W_USERINTERFACE_H
