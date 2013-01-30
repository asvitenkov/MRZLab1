#include "binnumber.h"

CBinNumber::CBinNumber()
    :mNumber(0)
{

}

CBinNumber::CBinNumber(int number)
    :mNumber(number)
{

}

CBinNumber::CBinNumber(const CBinNumber &copy)
{
    mNumber = copy.mNumber;
}

void CBinNumber::shift(SHIFT_DIRECTION direction)
{
    switch (direction)
    {
    case SD_LEFT:
        mNumber = mNumber << 1;
        break;
    case SD_RIGHT:
        mNumber = mNumber >> 1;
        break;
    }
}

void CBinNumber::shift(SHIFT_DIRECTION direction, int value)
{
    switch (direction)
    {
    case SD_LEFT:
        mNumber = mNumber << value;
        break;
    case SD_RIGHT:
        mNumber = mNumber >> value;
        break;
    }
}

void CBinNumber::operator=(const CBinNumber& copy)
{
    mNumber = copy.mNumber;
}



CBinNumber CBinNumber::operator+(const CBinNumber& number) const
{
    CBinNumber rNumber(this->mNumber+number.mNumber);
    return rNumber;
}
