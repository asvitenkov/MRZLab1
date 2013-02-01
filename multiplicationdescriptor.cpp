#include "multiplicationdescriptor.h"
#include "device.h"

CMultiplicationDescriptor::CMultiplicationDescriptor(CDevice *firstDevice, CDevice *secondDevice, QObject *parent) :
    CInputDescriptor(parent), mFirstDevice(firstDevice), mSecondDevice(secondDevice)
{

}



void CMultiplicationDescriptor::inputSignal(int firstNumber, int secondNumber)
{
    mFirstDevice->input(IN_FIRST, new CBinNumber(firstNumber));
    mFirstDevice->input(IN_SECOND, new CBinNumber(secondNumber));
    mSecondDevice->input(IN_FIRST, new CBinNumber(secondNumber));
}
