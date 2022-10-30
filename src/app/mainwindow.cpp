#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /********** General UI Setup*********************/
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Main");
    ui->tabWidget->setTabText(1, "Heating");
    ui->tabWidget->setTabText(2, "Sinking");
    ui->tabWidget->setTabText(3, "Cnt_Alignment");
    ui->tabWidget->setTabText(4, "Cooling");
    ui->tabWidget->setTabText(5, "Extracting");
    /********** Sinking process connections*********************/
    // open whs config
    connect(ui->actionwhs_config, &QAction::triggered, [this]() {
        sinkControll.on_actionwhs_config_triggered();
        });
    // connect cmd button execute delta
    connect(ui->execute_delta_subprocess, &QAbstractButton::pressed, [this]() {
        sinkControll.on_execute_delta_subprocess_clicked();
        });
    // connect cmd button run process sinking
    connect(ui->run_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.passLcdNum(ui->time_sinking);
        sinkControll.on_run_sinking_process_clicked();
        sinkControll.passLcdNum(ui->time_sinking);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.passLcdNum(ui->time_sinking);
        sinkControll.on_stop_sinking_process_clicked();
        sinkControll.passLcdNum(ui->time_sinking);
        });















    /********** XXX process connections*********************/





    // connect time monitor sinking
    //connect(&distance, &controller::valueChanged, [this]() {
    //    auto value = distance.getValue();
    //    qInfo() << "value distance controller changed, new value: " << value;
    //    qInfo() << "updating display with thread: " << QThread::currentThread();
     //  ui->temperature->display(value);
    //    });
    //auto dis = QtConcurrent::run(&controller::generateValues, &distance);

}

MainWindow::~MainWindow()
{

    delete ui;
}


 void MainWindow::on_actionExit_triggered()
{
    qInfo() << "application closed" << QThread::currentThread();
    connect(this,SIGNAL(triggered()),this,SLOT(close()));
} 