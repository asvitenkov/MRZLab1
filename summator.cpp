#include "summator.h"

CSummator::CSummator(QObject *parent) :
    CDevice(parent)
{
}



bool CSummator::run()
{
    bool bRes = true;

    if(mInputNumner.size() == 2)
    {
        if(mInputNumner.contains(IN_FIRST) && mInputNumner.contains(IN_SECOND))
        {
            CBinNumber *pFirst, *pSecond;
            pFirst = mInputNumner.value(IN_FIRST);
            pSecond = mInputNumner.value(IN_SECOND);




        }
        else
        {
            bRes = false;
        }
    }
    else
    {
        bRes = false;
    }

    return  CDevice::run() && bRes;
}
