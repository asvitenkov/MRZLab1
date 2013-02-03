#include "conveyor.h"
#include "conveyorline.h"
#include "shiftsummdevice.h"
#include "shiftsummdevicewidget.h"


CConveyor::CConveyor(QLayout *layout, ConveyorType type, QObject *parent) :
    QObject(parent), mConveyorType(type), mConveyorLine(NULL), mTime(0), mLayout(layout)
{
    createConveyorLine();
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
    CShiftSummDeviceWidget *wgt1 = new CShiftSummDeviceWidget(NUMBER_CAPACITY);
    CShiftSummDeviceWidget *wgt2 = new CShiftSummDeviceWidget(NUMBER_CAPACITY);
    CShiftSummDeviceWidget *wgt3 = new CShiftSummDeviceWidget(NUMBER_CAPACITY);
    CShiftSummDeviceWidget *wgt4 = new CShiftSummDeviceWidget(NUMBER_CAPACITY);
    CShiftSummDeviceWidget *wgt5 = new CShiftSummDeviceWidget(NUMBER_CAPACITY);
    CShiftSummDeviceWidget *wgt6 = new CShiftSummDeviceWidget(NUMBER_CAPACITY);

    mLayout->addWidget(wgt1);
    mLayout->addWidget(wgt2);
    mLayout->addWidget(wgt3);
    mLayout->addWidget(wgt4);
    mLayout->addWidget(wgt5);
    mLayout->addWidget(wgt6);

    wgt1->show();
    wgt2->show();
    wgt3->show();
    wgt4->show();
    wgt5->show();
    wgt6->show();



    CDevice *dev1 = new CShiftSummDevice(SD_LEFT,1,1,wgt1,this);
    mFirstDevice = dev1;
    CDevice *dev2 = new CShiftSummDevice(SD_LEFT,1,2,wgt2,this);
    CDevice *dev3 = new CShiftSummDevice(SD_LEFT,1,3,wgt3,this);
    CDevice *dev4 = new CShiftSummDevice(SD_LEFT,1,4,wgt4,this);
    CDevice *dev5 = new CShiftSummDevice(SD_LEFT,1,5,wgt5,this);
    CDevice *dev6 = new CShiftSummDevice(SD_LEFT,1,6,wgt6,this);
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


bool CConveyor::nextTime()
{
    if(mInputQueue.isEmpty() && isDone())
        return false;
    if(!mInputQueue.isEmpty()){
        PairNumber pair = mInputQueue.takeFirst();
        mConveyorLine->nextStep(pair.mFirstNumber, pair.mSecondNumber,0);
    }
    else
        mConveyorLine->nextStep();

}
