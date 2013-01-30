#include "shiftdevice.h"

CShiftDevice::CShiftDevice(SHIFT_DIRECTION direction, QObject *parent) :
    CDevice(parent), mShiftDirection(direction)
{
}

CShiftDevice::~CShiftDevice()
{

}

bool CShiftDevice::run()
{
    if( mInputNumbers.size()!=1 )
    {
        CDevice::run();
        return false;
    }

    if( !mInputNumbers.contains(IN_FIRST) )
    {
        CDevice::run();
        return false;
    }

    CBinNumber *pNumber = mInputNumbers.value(IN_FIRST);
    pNumber->shift(mShiftDirection);

    emit output(pNumber);


    return CDevice::run();
}
