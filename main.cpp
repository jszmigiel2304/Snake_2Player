#include "w_mainwindow.h"
#include "c_myqapplication.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    c_MyQApplication a(argc, argv);    
    w_MainWindow w(a.getWindowProperties());
    w.show();



    return a.exec();
}

