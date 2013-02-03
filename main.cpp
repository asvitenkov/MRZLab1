#include <QApplication>
#include "mainwindow.h"


// delete

#include "binnumber.h"
#include <QDebug>
#include "shiftsummdevice.h"
#include "shiftsummdevicewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
//    CBinNumber *n1 = new CBinNumber(15);
//    CBinNumber *n2 = new CBinNumber(15);
//    CBinNumber *n3 = new CBinNumber(0,NUMBER_CAPACITY*2);

//    CShiftSummDeviceWidget *w1 = new CShiftSummDeviceWidget();
//    CShiftSummDeviceWidget *w2 = new CShiftSummDeviceWidget();
//    CShiftSummDeviceWidget *w3 = new CShiftSummDeviceWidget();
//    CShiftSummDeviceWidget *w4 = new CShiftSummDeviceWidget();

//    w1->show();
//    w2->show();

//    qDebug() << n2->formattedString();
//    CShiftSummDevice device1(SD_LEFT, 1, 1,w1);
//    CShiftSummDevice device2(SD_LEFT, 1, 2,w2);
//    CShiftSummDevice device3(SD_LEFT, 1, 3,w3);
//    CShiftSummDevice device4(SD_LEFT, 1, 4,w4);
//    device1.input(IS_FIRST_NUMBER,n1);
//    device1.input(IS_SECOND_NUMBER,n2);
//    device1.input(IS_PREVIOUS_SUMM,n3);

//    QObject::connect(&device1,SIGNAL(output(InputSignal,CBinNumber*)),&device2,SLOT(input(InputSignal,CBinNumber*)));
//    QObject::connect(&device2,SIGNAL(output(InputSignal,CBinNumber*)),&device3,SLOT(input(InputSignal,CBinNumber*)));
//    QObject::connect(&device3,SIGNAL(output(InputSignal,CBinNumber*)),&device4,SLOT(input(InputSignal,CBinNumber*)));


//    device1.run();

//    device2.run();

//    device3.run();

//    device4.run();








    return a.exec();
}
