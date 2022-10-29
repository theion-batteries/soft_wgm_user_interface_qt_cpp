#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QTimer>
#include "controller.h"
#include <QtConcurrent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    controller distance;

    
};
#endif // MAINWINDOW_H
