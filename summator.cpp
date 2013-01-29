#include "summator.h"

CSummator::CSummator(QObject *parent) :
    CDevice(parent)
{
}



bool CSummator::run()
{
    bool result;


    return  CDevice::run() && result;
}
