#ifndef ABSTRACTCONVEYOR_H
#define ABSTRACTCONVEYOR_H

#include <QObject>
#include "binnumber.h"
#include "device.h"


class CIODescriptor;

class CAbstractConveyor : public QObject
{
    Q_OBJECT
public:
    explicit CAbstractConveyor(QVector<CDevice*>& devices, CIODescriptor *descriptor,QObject *parent = 0);
    virtual void nextStep(int firstNumber, int secondNumber) = 0;

protected:
    virtual bool isFree();

protected:
    QVector<CDevice*> mDevices;
    CIODescriptor* mIODescriptor;
signals:
    void output(CBinNumber*);

public slots:
    void outputConveyor(CBinNumber* number);
};

#endif // ABSTRACTCONVEYOR_H
