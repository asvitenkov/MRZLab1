#include "conveyor.h"
#include "device.h"
#include "defines.h"
#include "iodescriptor.h"

CConveyor::CConveyor(QVector<CDevice *> &devices, CIODescriptor *descriptor, QObject *parent) :
    CAbstractConveyor(devices,descriptor,parent)
{

}


void CConveyor::nextStep(int firstNumber, int secondNumber)
{
    if(mDevices.size()<2)
        return;
    // Передаём входные данные на вход нужных устройств

    // 1. Наверное нужно запустить с конца все девайсы
    for(int i=mDevices.size(); i>=0; ++i)
    {
        CDevice *pDevice = mDevices.at(i);
        if(!pDevice->isFree())
        {
            Q_ASSERT(pDevice->run());
        }
    }


    mIODescriptor->inputSignal(firstNumber,secondNumber);

    mIODescriptor->setOutput(this);


}



