#include "shiftsummdevicewidget.h"
#include "ui_shiftsummdevicewidget.h"

#include "binnumber.h"

CShiftSummDeviceWidget::CShiftSummDeviceWidget(int capacity, QWidget *parent) :
    QWidget(parent),mCapacity(capacity),
    ui(new Ui::CShiftSummDeviceWidget)
{
    ui->setupUi(this);
    ui->summEdit->setReadOnly(true);
    ui->multiplicandEdit->setReadOnly(true);
    ui->indexEdit->setReadOnly(true);
    ui->summEdit->setAlignment(Qt::AlignRight);
    ui->multiplicandEdit->setAlignment(Qt::AlignRight);
    ui->indexEdit->setAlignment(Qt::AlignRight);
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


void CShiftSummDeviceWidget::setNumberIndex(CBinNumber *number)
{
    ui->indexEdit->setText(QString::number(number->value()));
}


void CShiftSummDeviceWidget::clear()
{
    ui->indexEdit->clear();
    ui->summEdit->clear();
    ui->multiplicandEdit->clear();
}
