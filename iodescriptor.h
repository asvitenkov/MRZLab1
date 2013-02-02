#ifndef CINPUTDESCRIPTOR_H
#define CINPUTDESCRIPTOR_H

#include <QObject>
#include "abstractconveyor.h"

class CDevice;
class CAbstractConveyor;

class CIODescriptor : public QObject
{
    Q_OBJECT
public:
    explicit CIODescriptor(QObject *parent = 0);
    virtual void inputSignal(int firstNumber, int secondNumber) = 0;
    virtual void setOutput(CAbstractConveyor *conveyor) = 0;
    
signals:
    
public slots:
    
};

#endif // CINPUTDESCRIPTOR_H
