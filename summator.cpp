#include "summator.h"

CSummator::CSummator(QObject *parent) :
    CDevice(parent)
{
}



bool CSummator::run()
{

    if( mInputNumbers.size() != 2 )
    {
        CDevice::run();
        return false;
    }

    if( !mInputNumbers.contains(IN_FIRST) || !mInputNumbers.contains(IN_SECOND) )
    {
        CDevice::run();
        return false;
    }

    emit output( new CBinNumber( mInputNumbers.value(IN_FIRST)->value() + mInputNumbers.value(IN_SECOND)->value() ) );

    return  CDevice::run();
}
