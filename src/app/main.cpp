#include "mainwindow.h"
#define  _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Wafer Growing System User Interface");
    w.show();
     
    return a.exec();
}
