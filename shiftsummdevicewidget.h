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
    ~CShiftSummDeviceWidget();
    
public slots:
    void setSummNumber(CBinNumber* number);
    void setMultiplicand(CBinNumber* number);

private:
    int mCapacity;
    Ui::CShiftSummDeviceWidget *ui;


};

#endif // SHIFTSUMMDEVICEWIDGET_H
