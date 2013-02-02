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
    QMap<INPUT_SIGNAL, CBinNumber*> mInputSignals;




    
signals:
    void output(INPUT_SIGNAL inputSignal,CBinNumber *number);

public slots:
    void input(INPUT_SIGNAL inputSignal,CBinNumber *number);
};

#endif // CDEVICE_H
