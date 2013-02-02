#ifndef DEFINES_H
#define DEFINES_H

#define DEVICE_COUNT 6
#define NUMBER_CAPACITY 6

enum ShiftDirection
{
    SD_LEFT,
    SD_RIGHT
};


enum InputSignal
{
    IS_FIRST_NUMBER,
    IS_SECOND_NUMBER,
    IS_PREVIOUS_SUMM,
    IS_NUMBER_INDEX,
    IS_OUTPUT
};


enum ConveyorType
{
    CT_DEFAULT,
    CT_WAIT_FREE
};

struct PairNumber
{
    PairNumber()    :
        mFirstNumber(0), mSecondNumber(0)
    {

    }

    PairNumber(int fNumber, int sNumber):
        mFirstNumber(fNumber), mSecondNumber(sNumber)
    {
    }

    int mFirstNumber;
    int mSecondNumber;
};


#endif // DEFINES_H
