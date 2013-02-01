#ifndef MULTIPLICATIONDESCRIPTOR_H
#define MULTIPLICATIONDESCRIPTOR_H

#include "inputdescriptor.h"

class CDevice;

class CMultiplicationDescriptor : public CInputDescriptor
{
    Q_OBJECT
public:
    explicit CMultiplicationDescriptor(CDevice* firstDevice, CDevice* secondDevice, QObject *parent = 0);
    void inputSignal(int firstNumber, int secondNumber);

private:
    CDevice* mFirstDevice;
    CDevice* mSecondDevice;
signals:
    
public slots:
    
};

#endif // MULTIPLICATIONDESCRIPTOR_H
