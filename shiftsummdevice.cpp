#include "shiftsummdevice.h"
#include "shiftsummdevicewidget.h"


CShiftSummDevice::CShiftSummDevice(ShiftDirection direction, int shiftValue, int devicePos, CShiftSummDeviceWidget *widget, QObject *parent):
    CDevice(parent), mShiftDirection(direction), mShiftValue(shiftValue), mDevicePosition(devicePos), mWidget(widget)
{
    Q_ASSERT(widget);
}


CShiftSummDevice::~CShiftSummDevice()
{

}

bool CShiftSummDevice::run()
{
    if(mInputSignals.size()!=4)
        return false;

    if(!mInputSignals.contains(IS_FIRST_NUMBER) || !mInputSignals.contains(IS_SECOND_NUMBER)
            || !mInputSignals.contains(IS_PREVIOUS_SUMM) || !mInputSignals.contains(IS_NUMBER_INDEX))
        return false;

    mWidget->clear();

    CBinNumber *pFirstNumber, *pSecondNumber, *pPreviousSumm, *pNumberIndex;

    pFirstNumber = mInputSignals.value(IS_FIRST_NUMBER);
    pSecondNumber = mInputSignals.value(IS_SECOND_NUMBER);
    pPreviousSumm = mInputSignals.value(IS_PREVIOUS_SUMM);
    pNumberIndex = mInputSignals.value(IS_NUMBER_INDEX);

    pPreviousSumm->shift(mShiftDirection,mShiftValue);

    int sum = 0;

    if( (1<<(DEVICE_COUNT-mDevicePosition)) & pSecondNumber->value() )
        sum = pFirstNumber->value();

    emit output(IS_PREVIOUS_SUMM, new CBinNumber(sum + pPreviousSumm->value(),NUMBER_CAPACITY*2));
    emit output(IS_FIRST_NUMBER, new CBinNumber(*pFirstNumber));
    emit output(IS_SECOND_NUMBER, new CBinNumber(*pSecondNumber));
    emit output(IS_NUMBER_INDEX, new CBinNumber(*pNumberIndex));

    return CDevice::run();
}


void CShiftSummDevice::updateWidget()
{
    if(mInputSignals.contains(IS_PREVIOUS_SUMM))
        mWidget->setSummNumber(mInputSignals.value(IS_PREVIOUS_SUMM));
    if(mInputSignals.contains(IS_SECOND_NUMBER) && mInputSignals.contains(IS_FIRST_NUMBER))
    {
        CBinNumber *pSecondNumber, *pFirstNumber;
        pFirstNumber = mInputSignals.value(IS_FIRST_NUMBER);
        pSecondNumber = mInputSignals.value(IS_SECOND_NUMBER);
        if( (1<<(DEVICE_COUNT-mDevicePosition)) & pSecondNumber->value() )
            mWidget->setMultiplicand(pFirstNumber);
        else
        {
            CBinNumber zero(0);
            mWidget->setMultiplicand(&zero);
        }
    }

    if(mInputSignals.contains(IS_NUMBER_INDEX))
    {
        mWidget->setNumberIndex(mInputSignals.value(IS_NUMBER_INDEX));
    }

}

void CShiftSummDevice::clearWidget()
{
    mWidget->clear();
}


void CShiftSummDevice::resetDevice()
{
    CDevice::resetDevice();
    clearWidget();
}
