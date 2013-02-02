#ifndef MULTIPLICATIONDESCRIPTOR_H
#define MULTIPLICATIONDESCRIPTOR_H

#include "iodescriptor.h"

class CDevice;

class CMultiplicationDescriptor : public CIODescriptor
{
    Q_OBJECT
public:
    explicit CMultiplicationDescriptor(CDevice* firstDevice, CDevice* secondDevice, CDevice* outputDevice, QObject *parent = 0);
    void inputSignal(int firstNumber, int secondNumber);
    void setOutput(CAbstractConveyor *conveyor);


private:
    CDevice* mFirstDevice;
    CDevice* mSecondDevice;
    CDevice* mOutputDevice;
signals:
    
public slots:
    
};

#endif // MULTIPLICATIONDESCRIPTOR_H
