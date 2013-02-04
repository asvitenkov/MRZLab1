#ifndef CONVEYORLINE_H
#define CONVEYORLINE_H

#include <QObject>
#include <QQueue>
#include <QLayout>
#include "binnumber.h"


class CConveyorLine;
class CDevice;

class CConveyor : public QObject
{
    Q_OBJECT
public:
    explicit CConveyor(QLayout* layout,ConveyorType type = CT_DEFAULT, QObject *parent = 0);

    void addInputPair(int fNumber, int sNumber);
    bool isDone();
    bool nextTime();
    
private:
    void addOutputNumber(int number);
    void createConveyorLine();
    int getNextIndex();
    int getCurrentPairIndex(){ return mPairIndex; }
    ConveyorType mConveyorType;
    CConveyorLine *mConveyorLine;
    QQueue<PairNumber> mInputQueue;
    QList<int> mOutputList;
    CDevice *mFirstDevice;
    QLayout *mDevicesLayout;
    int mTime;
    int mPairIndex;
signals:
    void done();
    void inputPair(int, int, int);
    void output(int,int);
    void timeChanged(int);
private slots:
    void output(CBinNumber* number);
};

#endif // CONVEYOR_H
