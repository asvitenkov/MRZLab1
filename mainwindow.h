#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class CConveyor;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    CConveyor *mConveyor;



private slots:
    void addInputPair(int fNumber, int sNumber, int index);
    void addOutputNumber(int number, int index);
    void nextTimeSlot();
    void addRandomPair();
    void timeChanged(int time);
};

#endif // MAINWINDOW_H
