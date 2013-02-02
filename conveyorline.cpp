#include "conveyorline.h"
#include "device.h"

CConveyorLine::CConveyorLine(QVector<CDevice *> &devices, QObject *parent) :
    QObject(parent), mDevices(devices)
{

}


void CConveyorLine::nextStep(int firstNumber, int secondNumber, int index)
{
    if(mDevices.isEmpty())
        return;

    mDevices.first()->input(IS_FIRST_NUMBER,firstNumber);
    mDevices.first()->input(IS_SECOND_NUMBER,secondNumber);
    mDevices.first()->input(IS_PREVIOUS_SUMM,0);
    mDevices.first()->input(IS_NUMBER_INDEX,index);

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
