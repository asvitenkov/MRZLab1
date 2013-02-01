#ifndef REPEATER_H
#define REPEATER_H


#include "defines.h"
#include "device.h"

class CRepeater : public CDevice
{
    Q_OBJECT
public:
    explicit CRepeater(int position, QObject *parent = 0);
    virtual ~CRepeater();
    virtual bool run();

private:
    int mPosition;

signals:
    void repeatOutput(CBinNumber*);


public slots:
    
};

#endif // REPEATER_H
