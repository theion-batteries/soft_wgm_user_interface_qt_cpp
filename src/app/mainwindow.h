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
#include "processTabView.h"
#include "menuView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    Ui::MainWindow* getUi();
public slots:

private:
    Ui::MainWindow* ui;
/****************   view layer ******************/
    /********** process Tab View *********************/
    sinkingView* sinkView;
    cntAlignView* cntView;
    heatingView* heatView;
    extractingView* extractView;
    coolingView* coolView;
    mainView* managerView;
    /********** menu View *********************/
    menuEditView* editView;
    menuDebugView* debugView;
    menuFileView* fileView;
};
#endif // MAINWINDOW_H


