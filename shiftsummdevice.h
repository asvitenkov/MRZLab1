#ifndef SHIFTSUMMDEVICE_H
#define SHIFTSUMMDEVICE_H

#include "device.h"
#include "defines.h"



class CShiftSummDevice : public CDevice
{
    Q_OBJECT
public:
    explicit CShiftSummDevice(SHIFT_DIRECTION direction,int shiftValue, int devicePos,QObject *parent = 0);
    virtual ~CShiftSummDevice();
    bool run();


private:
    SHIFT_DIRECTION mShiftDirection;
    int mShiftValue;
    int mDevicePosition;

signals:
    
public slots:
    
};

#endif // SHIFTSUMMDEVICE_H
