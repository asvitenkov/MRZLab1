#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <QObject>
#include <QVector>
#include <QList>


#include "abstractconveyor.h"

class CConveyor : public CAbstractConveyor
{
    Q_OBJECT
public:
    explicit CConveyor(QVector<CDevice*>& devices,CIODescriptor *descriptor,QObject *parent = 0);
    void nextStep(int firstNumber, int secondNumber);
private:

signals:


public slots:
    
};

#endif // CONVEYOR_H
