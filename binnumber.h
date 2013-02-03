#ifndef CBINNUMBER_H
#define CBINNUMBER_H




#include <QObject>
#include <QList>

#include "defines.h"

class CBinNumber
{
public:
    //explicit CBinNumber(int capacity);
    explicit CBinNumber(int number,int capacity = NUMBER_CAPACITY);
    CBinNumber(const CBinNumber& copy);
    void shift(ShiftDirection direction);
    void shift(ShiftDirection direction, int value);
    int value();
    inline QString stringValue(){ return mNumber; }
    inline int capacity(){ return mCapacity; }
    void operator=(const CBinNumber& copy);
    CBinNumber operator+(const CBinNumber& nimber) const;
    QString formattedString();

signals:
    
public slots:
    
private:
    QString mNumber;
    int mCapacity;
};

#endif // CBINNUMBER_H
