#include <QApplication>
#include "mainwindow.h"

#include <QTextCodec>

// delete

#include "binnumber.h"
#include <QDebug>
#include "shiftsummdevice.h"
#include "shiftsummdevicewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setStyle("Cleanlooks");

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    MainWindow w;
    w.show();

    return a.exec();
}
