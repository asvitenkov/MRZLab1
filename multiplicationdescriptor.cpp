#include "multiplicationdescriptor.h"
#include "device.h"

CMultiplicationDescriptor::CMultiplicationDescriptor(CDevice *firstDevice, CDevice *secondDevice, CDevice *outputDevice, QObject *parent) :
    CIODescriptor(parent), mFirstDevice(firstDevice), mSecondDevice(secondDevice), mOutputDevice(outputDevice)
{

}



void CMultiplicationDescriptor::inputSignal(int firstNumber, int secondNumber)
{
    mFirstDevice->input(IN_FIRST, new CBinNumber(firstNumber));
    mFirstDevice->input(IN_SECOND, new CBinNumber(secondNumber));
    mSecondDevice->input(IN_FIRST, new CBinNumber(secondNumber));
}


void CMultiplicationDescriptor::setOutput(CAbstractConveyor *conveyor)
{
    connect(mOutputDevice,SIGNAL(output(CBinNumber*)),conveyor,SLOT(outputConveyor(CBinNumber*)));
}
