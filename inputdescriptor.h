#ifndef CINPUTDESCRIPTOR_H
#define CINPUTDESCRIPTOR_H

#include <QObject>

class CInputDescriptor : public QObject
{
    Q_OBJECT
public:
    explicit CInputDescriptor(QObject *parent = 0);
    virtual void inputSignal(int firstNumber, int secondNumber) = 0;
    
signals:
    
public slots:
    
};

#endif // CINPUTDESCRIPTOR_H
