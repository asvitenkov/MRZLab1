#include <QApplication>
#include "mainwindow.h"


// delete

#include "binnumber.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    CBinNumber n1(123,6);
    n1.shift(SD_LEFT,4);
    qDebug() << n1.value();



    return a.exec();
}
