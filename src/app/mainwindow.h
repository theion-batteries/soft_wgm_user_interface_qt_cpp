#ifndef MAINWINDOW_H
#define MAINWINDOW_H
// qt headers
#include <QMainWindow>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QTimer>
#include <QLabel>
#include <QTabWidget>
#include <QtConcurrent>
// app headers
#include "sinkingView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
public slots:

    void on_actionExit_triggered();

private:
    Ui::MainWindow* ui;
    //controller distance;
    sinkingController sinkControll;

};
#endif // MAINWINDOW_H
