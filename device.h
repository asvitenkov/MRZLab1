#ifndef CDEVICE_H
#define CDEVICE_H

#include <QObject>
#include <QVector>
#include <QMap>

#include  "binnumber.h"

class CDevice : public QObject
{
    Q_OBJECT
public:
    explicit CDevice(QObject *parent = 0);
    virtual bool isFree() { return mInputSignals.isEmpty(); }
    virtual ~CDevice();
    virtual bool run();

protected:
    QMap<InputSignal, CBinNumber*> mInputSignals;




    
signals:
    void output(InputSignal inputSignal,CBinNumber *number);

public slots:
    void input(InputSignal inputSignal,CBinNumber *number);
};

#endif // CDEVICE_H
