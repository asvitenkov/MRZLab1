#ifndef CONVEYORLINE_H
#define CONVEYORLINE_H

#include <QObject>
#include <QQueue>
#include "binnumber.h"


class CConveyorLine;
class CDevice;

class CConveyor : public QObject
{
    Q_OBJECT
public:
    explicit CConveyor(ConveyorType type = CT_DEFAULT, QObject *parent = 0);
    void addInputPair(int fNumber, int sNumber);
    bool isDone();
    
private:
    void addOutputNumber(int number);
    void createConveyorLine();
    ConveyorType mConveyorType;
    CConveyorLine *mConveyorLine;
    QQueue<PairNumber> mInputQueue;
    QList<int> mOutputList;
    CDevice *mFirstDevice;
    int mTime;
signals:
    void done();
private slots:
    void output(CBinNumber* number);
};

#endif // CONVEYOR_H
