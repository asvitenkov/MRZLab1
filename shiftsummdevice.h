#ifndef SHIFTSUMMDEVICE_H
#define SHIFTSUMMDEVICE_H

#include "device.h"
#include "defines.h"



class CShiftSummDevice : public CDevice
{
    Q_OBJECT
public:
    explicit CShiftSummDevice(SHIFT_DIRECTION direction,int shiftValue, QObject *parent = 0);
    virtual ~CShiftSummDevice();
    bool run();


private:
    int mShiftValue;
    SHIFT_DIRECTION mShiftDirection;


signals:
    
public slots:
    
};

#endif // SHIFTSUMMDEVICE_H
