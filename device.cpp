#include "device.h"

CDevice::CDevice(QObject *parent) :
    QObject(parent)
{
}



CDevice::~CDevice()
{

}


void CDevice::input(INPUT_NUMBER inputNumber, CBinNumber *number)
{
    Q_ASSERT(!mInputNumbers.contains(inputNumber));
    mInputNumbers.insert(inputNumber, number);
}


bool CDevice::run()
{

    qDeleteAll(mInputNumbers.begin(), mInputNumbers.end());
    mInputNumbers.clear();

    return true;
}
