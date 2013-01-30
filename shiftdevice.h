#ifndef SHIFTDEVICE_H
#define SHIFTDEVICE_H

#include "device.h"


class CShiftDevice : public CDevice
{
    Q_OBJECT
public:
    explicit CShiftDevice(SHIFT_DIRECTION direction, QObject *parent = 0);
    virtual ~CShiftDevice();
    virtual bool run();

signals:
    
public slots:
    
private:
    SHIFT_DIRECTION mShiftDirection;

};

#endif // SHIFTDEVICE_H
