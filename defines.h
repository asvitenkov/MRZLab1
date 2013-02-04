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
    PairNumber(int fNumber, int sNumber, int index):
        mFirstNumber(fNumber), mSecondNumber(sNumber), mIndex(index)
    {
    }

    int mFirstNumber;
    int mSecondNumber;
    int mIndex;
};


#endif // DEFINES_H
