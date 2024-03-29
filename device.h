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
    virtual void resetDevice();

protected:

    QMap<InputSignal, CBinNumber*> mInputSignals;


protected:
    virtual void updateWidget() = 0;
    virtual void clearWidget() = 0;

    
signals:
    void output(InputSignal inputSignal,CBinNumber *number);

public slots:
    void input(InputSignal inputSignal,CBinNumber *number);
};

#endif // CDEVICE_H
