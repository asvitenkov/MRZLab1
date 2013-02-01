#include "shiftsummdevice.h"

CShiftSummDevice::CShiftSummDevice(SHIFT_DIRECTION direction, int shiftValue, QObject *parent) :
    CDevice(parent), mShiftDirection(direction), mShiftValue(shiftValue)
{

}


CShiftSummDevice::~CShiftSummDevice()
{

}

bool CShiftSummDevice::run()
{
    if(mInputNumbers.size()!=2)
        return false;

    if(!mInputNumbers.contains(IN_FIRST) || !mInputNumbers.contains(IN_SECOND))
        return false;

    CBinNumber *pFirstNumber, *pSecondNumber;

    pFirstNumber = mInputNumbers.value(IN_FIRST);
    pSecondNumber = mInputNumbers.value(IN_SECOND);


    pFirstNumber->shift(mShiftDirection,mShiftValue);

    emit output(new CBinNumber(pFirstNumber->value()+pSecondNumber->value()));

    return CDevice::run();
}
