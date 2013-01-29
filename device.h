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
    virtual ~CDevice();

private:
    QMap<INPUT_NUMBER, CBinNumber> mInputNumner;


protected:
    virtual bool run();

    
signals:
    void output();

public slots:
    void input(INPUT_NUMBER inputNumber,CBinNumber number);
};

#endif // CDEVICE_H
