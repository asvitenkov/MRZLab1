#include "shiftsummdevicewidget.h"
#include "ui_shiftsummdevicewidget.h"

#include "binnumber.h"

CShiftSummDeviceWidget::CShiftSummDeviceWidget(int capacity, QWidget *parent) :
    QWidget(parent),mCapacity(capacity),
    ui(new Ui::CShiftSummDeviceWidget)
{
    ui->setupUi(this);
}

CShiftSummDeviceWidget::~CShiftSummDeviceWidget()
{
    delete ui;
}


void CShiftSummDeviceWidget::setMultiplicand(CBinNumber *number)
{
    ui->multiplicandEdit->setText(number->formattedString());
}

void CShiftSummDeviceWidget::setSummNumber(CBinNumber *number)
{
    ui->summEdit->setText(number->formattedString());
}
