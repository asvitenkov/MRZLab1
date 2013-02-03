#ifndef SHIFTSUMMDEVICE_H
#define SHIFTSUMMDEVICE_H

#include "device.h"
#include "defines.h"

class CShiftSummDeviceWidget;

class CShiftSummDevice : public CDevice
{
    Q_OBJECT
public:
    explicit CShiftSummDevice(ShiftDirection direction,int shiftValue, int devicePos,CShiftSummDeviceWidget* widget,QObject *parent = 0);
    virtual ~CShiftSummDevice();
    bool run();


private:
    void updateWidget();

    ShiftDirection mShiftDirection;
    int mShiftValue;
    int mDevicePosition;
    CShiftSummDeviceWidget *mWidget;

signals:
    
public slots:
    
};

#endif // SHIFTSUMMDEVICE_H
