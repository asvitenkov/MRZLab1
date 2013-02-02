#include "conveyor.h"
#include "conveyorline.h"
#include "shiftsummdevice.h"


CConveyor::CConveyor(ConveyorType type, QObject *parent) :
    QObject(parent), mConveyorType(type), mConveyorLine(NULL), mTime(0)
{
}


void CConveyor::addInputPair(int fNumber, int sNumber)
{
    mInputQueue.push_back(PairNumber(fNumber,sNumber));
}


bool CConveyor::isDone()
{
    return (mInputQueue.isEmpty() && mConveyorLine->isFree());
}


void CConveyor::output(CBinNumber *number)
{
    addOutputNumber(number->value());
    delete number;
}

void CConveyor::addOutputNumber(int number)
{
     mOutputList.push_back(number);
}

void CConveyor::createConveyorLine()
{
    QVector<CDevice*> devices;
    CDevice *dev1 = new CShiftSummDevice(SD_RIGHT,1,1,this);
    mFirstDevice = dev1;
    CDevice *dev2 = new CShiftSummDevice(SD_RIGHT,1,2,this);
    CDevice *dev3 = new CShiftSummDevice(SD_RIGHT,1,3,this);
    CDevice *dev4 = new CShiftSummDevice(SD_RIGHT,1,4,this);
    CDevice *dev5 = new CShiftSummDevice(SD_RIGHT,1,5,this);
    CDevice *dev6 = new CShiftSummDevice(SD_RIGHT,1,6,this);
    devices.push_back(dev1);
    devices.push_back(dev2);
    devices.push_back(dev3);
    devices.push_back(dev4);
    devices.push_back(dev5);
    devices.push_back(dev6);
    connect(dev1,SIGNAL(output(InputSignal,CBinNumber*)),dev2,SLOT(input(InputSignal,CBinNumber*)));
    connect(dev2,SIGNAL(output(InputSignal,CBinNumber*)),dev3,SLOT(input(InputSignal,CBinNumber*)));
    connect(dev3,SIGNAL(output(InputSignal,CBinNumber*)),dev4,SLOT(input(InputSignal,CBinNumber*)));
    connect(dev4,SIGNAL(output(InputSignal,CBinNumber*)),dev5,SLOT(input(InputSignal,CBinNumber*)));
    connect(dev5,SIGNAL(output(InputSignal,CBinNumber*)),dev6,SLOT(input(InputSignal,CBinNumber*)));



    mConveyorLine = new CConveyorLine(devices,this);

    connect(dev6,SIGNAL(output(InputSignal,CBinNumber*)),mConveyorLine,SLOT(outputConveyor(InputSignal,CBinNumber*)));
    connect(mConveyorLine,SIGNAL(output(CBinNumber*)),this,SLOT(output(CBinNumber*)));
}
