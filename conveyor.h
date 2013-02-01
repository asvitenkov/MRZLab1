#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <QObject>
#include <QVector>
#include <QList>

class CDevice;
class CBinNumber;
class CInputDescriptor;

class CConveyor : public QObject
{
    Q_OBJECT
public:
    explicit CConveyor(QVector<CDevice*>& devices,CInputDescriptor *inputDescriptor,QObject *parent = 0);
    void nextStep(int firstNumber, int secondNumber);
private:
    QVector<CDevice*> mDevices;
    CInputDescriptor* mInputDescriptor;
signals:
    void firstOutput(CBinNumber*);
    void secondOutput(CBinNumber*);

public slots:
    
};

#endif // CONVEYOR_H
