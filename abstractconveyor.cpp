#include "abstractconveyor.h"

CAbstractConveyor::CAbstractConveyor(QVector<CDevice *> &devices, CIODescriptor *descriptor, QObject *parent) :
    QObject(parent), mDevices(devices), mIODescriptor(descriptor)
{
}


bool CAbstractConveyor::isFree()
{
    for(int i=0; i<mDevices.size(); ++i)
        if(!mDevices.at(i)->isFree())
            return false;

    return true;
}



void CAbstractConveyor::outputConveyor(CBinNumber *number)
{
    emit output(number);
}
