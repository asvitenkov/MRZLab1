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
    
    CBinNumber n1(16);
    CBinNumber n2(3);
    qDebug() << (n1+n2).value();


    return a.exec();
}
