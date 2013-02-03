#include "conveyorline.h"
#include "device.h"

CConveyorLine::CConveyorLine(QVector<CDevice *> &devices, QObject *parent) :
    QObject(parent), mDevices(devices)
{

}

void CConveyorLine::nextStep()
{
    if(mDevices.isEmpty())
        return;

    for(int i=mDevices.size()-1; i>=0; --i)
    {
        CDevice *pDevice = mDevices.at(i);
        if(!pDevice->isFree())
        {
            Q_ASSERT(pDevice->run());
        }
    }
}


void CConveyorLine::nextStep(int firstNumber, int secondNumber, int index)
{
    if(mDevices.isEmpty())
        return;


    nextStep();


    // Передаём входные данные на вход нужных устройств

    // 1. Наверное нужно запустить с конца все девайсы


    mDevices.first()->input(IS_FIRST_NUMBER, new CBinNumber(firstNumber));
    mDevices.first()->input(IS_SECOND_NUMBER, new CBinNumber(secondNumber));
    mDevices.first()->input(IS_PREVIOUS_SUMM, new CBinNumber(0,NUMBER_CAPACITY*2));
    mDevices.first()->input(IS_NUMBER_INDEX, new CBinNumber(index));

}



void CConveyorLine::outputConveyor(InputSignal signal, CBinNumber *number)
{
    if( signal!= IS_PREVIOUS_SUMM )
        return;
    emit output(number);
}

bool CConveyorLine::isFree()
{
    for(int i=0; i<mDevices.size(); ++i)
        if(!mDevices.at(i)->isFree())
            return false;
    return true;
}
