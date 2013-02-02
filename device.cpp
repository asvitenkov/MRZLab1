#include "device.h"

CDevice::CDevice(QObject *parent) :
    QObject(parent)
{
}



CDevice::~CDevice()
{

}


void CDevice::input(INPUT_SIGNAL inputSignal, CBinNumber *number)
{
    Q_ASSERT(!mInputSignals.contains(inputSignal));
    mInputSignals.insert(inputSignal, number);
}


bool CDevice::run()
{
    qDeleteAll(mInputSignals.begin(), mInputSignals.end());
    mInputSignals.clear();
    return true;
}
