#ifndef SUMMATOR_H
#define SUMMATOR_H

#include "device.h"

class CSummator : public CDevice
{
    Q_OBJECT
public:
    explicit CSummator(QObject *parent = 0);
    bool run();
signals:
    
public slots:
    
};

#endif // SUMMATOR_H
