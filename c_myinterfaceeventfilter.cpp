#include "c_myinterfaceeventfilter.h"

c_myInterfaceEventFilter::c_myInterfaceEventFilter(QObject *parent)
    : QObject{parent}
{

}

bool c_myInterfaceEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    switch(event->type()) {
    case QEvent::Enter: {
        if(obj->objectName() == "startButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::PointingHandCursor); return true;}
        if(obj->objectName() == "settingButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::PointingHandCursor); return true;}
        if(obj->objectName() == "closeButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::PointingHandCursor); return true;}
        if(obj->objectName() == "joinButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::PointingHandCursor); return true;}
        if(obj->objectName() == "newButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::PointingHandCursor); return true;}


    }
    case QEvent::Leave: {
        if(obj->objectName() == "startButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::ArrowCursor); return true;}
        if(obj->objectName() == "settingButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::ArrowCursor); return true;}
        if(obj->objectName() == "closeButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::ArrowCursor); return true;}
        if(obj->objectName() == "joinButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::ArrowCursor); return true;}
        if(obj->objectName() == "newButtonWidget") { dynamic_cast<QWidget *>(obj)->setCursor(Qt::ArrowCursor); return true;}
    }
    case QEvent::MouseButtonRelease: {
        event->accept();
    }
    default: {
        return QObject::eventFilter(obj, event);
    }
    }
}
