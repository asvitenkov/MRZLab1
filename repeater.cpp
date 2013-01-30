#include "repeater.h"

CRepeater::CRepeater(QObject *parent) :
    CDevice(parent)
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

    emit output(new CBinNumber(mInputNumbers.value(IN_FIRST)->value()));


    return CDevice::run();
}
