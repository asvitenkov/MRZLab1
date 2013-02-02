#include "binnumber.h"

//CBinNumber::CBinNumber(int capacity)
//    :mCapacity(capacity)
//{
//    for(int i=0;i<capacity; i++)
//        mNumber+='0';
//}

CBinNumber::CBinNumber(int number, int capacity)
    :mNumber(QString::number(number,2)), mCapacity(capacity)
{
    if(mNumber.size()>capacity)
    {
        mNumber.clear();
        for(int i=0; i<capacity; i++)
            mNumber+='0';
    }

    int size = capacity - mNumber.size();
    for(int i=0; i< size; i++)
        mNumber.push_front('0');
}

CBinNumber::CBinNumber(const CBinNumber &copy)
{
    mNumber = copy.mNumber;
    mCapacity = copy.mCapacity;
}

void CBinNumber::shift(SHIFT_DIRECTION direction)
{

    QChar ch;

    switch (direction)
    {
    case SD_LEFT:
        ch = mNumber.at(0);
        mNumber = mNumber.remove(0,1);
        mNumber+=ch;
        break;
    case SD_RIGHT:
        ch = mNumber.at(mNumber.size()-1);
        mNumber = mNumber.remove(mNumber.size()-1);
        mNumber.push_front(ch);
        break;
    }
}

void CBinNumber::shift(SHIFT_DIRECTION direction, int value)
{
    for(int i=0; i<value; i++)
            shift(direction);

}

void CBinNumber::operator=(const CBinNumber& copy)
{
    mNumber = copy.mNumber;
}



CBinNumber CBinNumber::operator+(const CBinNumber& number) const
{
    CBinNumber rNumber(this->mNumber.toInt()+number.mNumber.toInt());
    return rNumber;
}


int CBinNumber::value()
{
    bool ok;
    int res = mNumber.toInt(&ok,2);
    return res;
}
