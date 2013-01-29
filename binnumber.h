#ifndef CBINNUMBER_H
#define CBINNUMBER_H




#include <QObject>

#include "defines.h"

class CBinNumber
{
public:
    explicit CBinNumber();
    explicit CBinNumber(int number);
    CBinNumber(const CBinNumber& copy);
    void shift(SHIFT_DIRECTION direction);
    void shift(SHIFT_DIRECTION direction, int value);
    inline int value(){ return mNumber; }
    void operator=(const CBinNumber& copy);
signals:
    
public slots:
    
private:
    int mNumber;
};

#endif // CBINNUMBER_H
