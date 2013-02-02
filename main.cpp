#include <QApplication>
#include "mainwindow.h"


// delete

#include "binnumber.h"
#include <QDebug>
#include "shiftsummdevice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    CBinNumber *n1 = new CBinNumber(15);
    CBinNumber *n2 = new CBinNumber(15);
    CBinNumber *n3 = new CBinNumber(0,NUMBER_CAPACITY*2);
    CShiftSummDevice device1(SD_LEFT, 1, 1);
    CShiftSummDevice device2(SD_LEFT, 1, 2);
    CShiftSummDevice device3(SD_LEFT, 1, 3);
    CShiftSummDevice device4(SD_LEFT, 1, 4);
    device1.input(IS_FIRST_NUMBER,n1);
    device1.input(IS_SECOND_NUMBER,n2);
    device1.input(IS_PREVIOUS_SUMM,n3);

    QObject::connect(&device1,SIGNAL(output(INPUT_SIGNAL,CBinNumber*)),&device2,SLOT(input(INPUT_SIGNAL,CBinNumber*)));
    QObject::connect(&device2,SIGNAL(output(INPUT_SIGNAL,CBinNumber*)),&device3,SLOT(input(INPUT_SIGNAL,CBinNumber*)));
    QObject::connect(&device3,SIGNAL(output(INPUT_SIGNAL,CBinNumber*)),&device4,SLOT(input(INPUT_SIGNAL,CBinNumber*)));


    device1.run();

    device2.run();

    device3.run();

    device4.run();








    return a.exec();
}
