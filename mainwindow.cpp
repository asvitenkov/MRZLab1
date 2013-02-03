#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "conveyor.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CConveyor *conveyor = new CConveyor(ui->verticalLayout,CT_DEFAULT,this);
    conveyor->addInputPair(63,63);
    //conveyor->addInputPair(1,1);
    conveyor->nextTime();
    conveyor->nextTime();
    conveyor->nextTime();
    conveyor->nextTime();
    conveyor->nextTime();
    conveyor->nextTime();
    conveyor->nextTime();

}

MainWindow::~MainWindow()
{
    delete ui;
}
