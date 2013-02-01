#include "repeater.h"

CRepeater::CRepeater(int position, QObject *parent) :
    CDevice(parent), mPosition(position)
{

}


CRepeater::~CRepeater()
{

}


bool CRepeater::run()
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

    emit repeatOutput(new CBinNumber(*mInputNumbers.value(IN_FIRST)));
    emit output(new CBinNumber(*mInputNumbers.value(IN_FIRST)));


    return CDevice::run();
}
