#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <QObject>
#include <QVector>
#include <QList>


#include "defines.h"

class CDevice;
class CBinNumber;

class CConveyorLine : public QObject
{
    Q_OBJECT
public:
    explicit CConveyorLine(QVector<CDevice*>& devices,QObject *parent = 0);
    void nextStep(int firstNumber, int secondNumber);
    bool isFree();

private:
    QVector<CDevice*> mDevices;
signals:
    void output(CBinNumber*);

public slots:
    void outputConveyor(InputSignal signal,CBinNumber* number);
};

#endif // CONVEYOR_H
