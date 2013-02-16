#ifndef SHIFTSUMMDEVICEWIDGET_H
#define SHIFTSUMMDEVICEWIDGET_H

#include <QWidget>
#include "defines.h"

class CBinNumber;

namespace Ui {
class CShiftSummDeviceWidget;
}

class CShiftSummDeviceWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit CShiftSummDeviceWidget(int capacity = NUMBER_CAPACITY,QWidget *parent = 0);
    void clear();
    ~CShiftSummDeviceWidget();
    
public slots:
    void setSummNumber(CBinNumber* number);
    void setMultiplicand(CBinNumber* number);
    void setNumberIndex(CBinNumber* number);
    void setFirsrNumber(CBinNumber* number);
    void setSecondNumber(CBinNumber* number);

private:
    int mCapacity;
    Ui::CShiftSummDeviceWidget *ui;


};

#endif // SHIFTSUMMDEVICEWIDGET_H
