#include "w_userinterface.h"

w_UserInterface::w_UserInterface(QWidget *parent)
    : QWidget{parent}
{
    myEventFilter = new c_myInterfaceEventFilter;
}

c_myInterfaceEventFilter *w_UserInterface::getMyEventFilter() const
{
    return myEventFilter;
}

void w_UserInterface::createInterface()
{
    createTopBox();
    createCentralBox();
    createBottomBox();
}
