#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <QObject>
#include <QVector>
#include <QList>

#include "device.h"
#include "defines.h"

class CConveyor : public QObject
{
    Q_OBJECT
public:
    explicit CConveyor(QVector<CDevice*>& devices,QObject *parent = 0);
    void nextStep(int firstNumber, int secondNumber);
    bool isFree();

private:
    QVector<CDevice*> mDevices;
signals:
    void output(CBinNumber*);

public slots:
    void outputConveyor(CBinNumber* number);
};

#endif // CONVEYOR_H
