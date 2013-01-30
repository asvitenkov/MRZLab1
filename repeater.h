#ifndef REPEATER_H
#define REPEATER_H


#include "defines.h"
#include "device.h"

class CRepeater : public CDevice
{
    Q_OBJECT
public:
    explicit CRepeater(QObject *parent = 0);
    virtual ~CRepeater();
    virtual bool run();
signals:
    
public slots:
    
};

#endif // REPEATER_H
