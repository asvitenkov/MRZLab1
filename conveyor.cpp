#include "conveyor.h"
#include "device.h"
#include "defines.h"
#include "inputdescriptor.h"

CConveyor::CConveyor(QVector<CDevice *> &devices, CInputDescriptor *inputDescriptor, QObject *parent) :
    QObject(parent), mDevices(devices), mInputDescriptor(inputDescriptor)
{

}


void CConveyor::nextStep(int firstNumber, int secondNumber)
{
    if(mDevices.size()<2)
        return;

    mInputDescriptor->inputSignal(firstNumber,secondNumber);

    // 1. Наверное нужно запустить с конца все девайсы

}
