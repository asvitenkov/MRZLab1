#include <QTime>
#include <QLCDNumber>
#include <QInputDialog>
#include "math.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "conveyor.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    mConveyor = new CConveyor(ui->deviceLayout,CT_DEFAULT,this);


    ui->rbtnConveyorType->setChecked(true);
    ui->btnStop->hide();
//    ui->btnStart->hide();


    connect(ui->btnNextTime,SIGNAL(clicked()),this,SLOT(nextTimeSlot()));
    connect(ui->btnRandomPair,SIGNAL(clicked()),this,SLOT(addRandomPair()));
    connect(mConveyor,SIGNAL(inputPair(int,int,int)),this,SLOT(addInputPair(int,int,int)));
    connect(mConveyor,SIGNAL(output(int,int)),this,SLOT(addOutputNumber(int,int)));
    connect(mConveyor,SIGNAL(timeChanged(int)),this,SLOT(timeChanged(int)));
    connect(ui->btnResetConveyor,SIGNAL(clicked()),this,SLOT(resetConveyor()));
    connect(ui->rbtnConveyorType,SIGNAL(clicked()),SLOT(changeConveyorType()));
    connect(ui->rbtnLineType,SIGNAL(clicked()),SLOT(changeConveyorType()));
    connect(ui->btnGenNPairs,SIGNAL(clicked()),this,SLOT(addNPairs()));
    connect(ui->btnStart,SIGNAL(clicked()),SLOT(startConveyor()));
    connect(ui->btnStop,SIGNAL(clicked()),SLOT(stopConveyor()));

    connect(&mTimer,SIGNAL(timeout()),this,SLOT(nextTimeSlot()));

    ui->statusBar->showMessage("Такт 0");


    qsrand(QTime::currentTime().msec());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::nextTimeSlot()
{
    if(!mConveyor->nextTime())
    {
        stopConveyor();
    }
}


void MainWindow::addRandomPair()
{
    int maxNumber = pow(2,NUMBER_CAPACITY);

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

//    QLCDNumber *number
//    ui->statusBar->addWidget();
    ui->statusBar->showMessage(QString("Такт %1").arg(time));
    //ui->statusBar->
}

void MainWindow::resetConveyor()
{
    mConveyor->resetConveyour();
    ui->lstInputNumbers->clear();
    ui->lstOutputNumbers->clear();
    ui->statusBar->showMessage("Такт 0");
}



void MainWindow::changeConveyorType()
{
    ConveyorType type;
    if(ui->rbtnConveyorType->isChecked())
        type = CT_DEFAULT;
    else
        type = CT_WAIT_FREE;

    mConveyor->setType(type);


    ui->lstInputNumbers->clear();
    ui->lstOutputNumbers->clear();
    ui->statusBar->showMessage("Такт 0");
}



void MainWindow::startConveyor()
{
    ui->btnStart->hide();
    ui->btnStop->show();
    mTimer.start(ui->spinBox->value());
}


void MainWindow::stopConveyor()
{
    ui->btnStart->show();
    ui->btnStop->hide();
    mTimer.stop();
}



void MainWindow::addNPairs()
{
    bool ok;
    int n = QInputDialog::getInt(this,"Количество пар","Введите количество генерируемых пар входных чисел",0,0,10000,1,&ok);
    if(!ok)
        return;

    for(int i=0; i<n; i++)
    {
        addRandomPair();
    }
}
