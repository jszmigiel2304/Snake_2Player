#ifndef C_INTERFACEFACTORY_H
#define C_INTERFACEFACTORY_H

#include "_myData.h"

#include <QObject>
#include <QWidget>
#include <QPushButton>

class c_interfaceFactory : public QObject
{
    Q_OBJECT
public:
    explicit c_interfaceFactory(QObject *parent = nullptr);
    ~c_interfaceFactory();

static QWidget *createWidget(Interface_NS::WidgetType type, QWidget *parent, QObject * eventFilter = nullptr);
static QWidget *createUserInterface(Interface_NS::InterfaceType type, QWidget *parent);

signals:

};

#endif // C_INTERFACEFACTORY_H
