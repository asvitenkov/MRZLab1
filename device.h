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
    virtual bool isFree() { return mInputNumbers.isEmpty(); }
    virtual ~CDevice();
    virtual bool run();

protected:
    QMap<INPUT_NUMBER, CBinNumber*> mInputNumbers;




    
signals:
    void output(CBinNumber*);

public slots:
    void input(INPUT_NUMBER inputNumber,CBinNumber *number);
};

#endif // CDEVICE_H
