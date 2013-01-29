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
    
    CBinNumber number(16);
    number.shift(SD_LEFT,2);
    qDebug() << number.value();


    return a.exec();
}
