#include "device.h"

CDevice::CDevice(QObject *parent) :
    QObject(parent)
{
}



CDevice::~CDevice()
{

}


void CDevice::input(INPUT_NUMBER inputNumber, CBinNumber number)
{
    Q_ASSERT(!mInputNumner.contains(inputNumber));
    mInputNumner.insert(inputNumber, number);
}


bool CDevice::run()
{
    mInputNumner.clear();
    return true;
}
