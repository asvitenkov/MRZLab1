#include <QTime>
#include "math.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "conveyor.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    mConveyor = new CConveyor(ui->deviceLayout,CT_WAIT_FREE,this);

    connect(ui->btnNextTime,SIGNAL(clicked()),this,SLOT(nextTimeSlot()));
    connect(ui->btnRandomPair,SIGNAL(clicked()),this,SLOT(addRandomPair()));
    connect(mConveyor,SIGNAL(inputPair(int,int,int)),this,SLOT(addInputPair(int,int,int)));
    connect(mConveyor,SIGNAL(output(int,int)),this,SLOT(addOutputNumber(int,int)));
    connect(mConveyor,SIGNAL(timeChanged(int)),this,SLOT(timeChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::nextTimeSlot()
{
    mConveyor->nextTime();
}


void MainWindow::addRandomPair()
{
    int maxNumber = pow(2,NUMBER_CAPACITY);
    qsrand(QTime::currentTime().msec());
    mConveyor->addInputPair(qrand()%maxNumber, qrand()%maxNumber);
}

void MainWindow::addInputPair(int fNumber, int sNumber, int index)
{
    ui->lstInputNumbers->addItem(QString("%1: %2, %3").arg(index).arg(fNumber).arg(sNumber));
}

void MainWindow::addOutputNumber(int number, int index)
{
    ui->lstOutputNumbers->addItem(QString("%1: %2").arg(index).arg(number));
}

void MainWindow::timeChanged(int time)
{
    ui->statusBar->showMessage(QString("Такт %1").arg(time));
}
