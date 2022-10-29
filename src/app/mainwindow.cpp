#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Main");
    ui->tabWidget->setTabText(1, "Heating");
    ui->tabWidget->setTabText(2, "Sinking");
    ui->tabWidget->setTabText(3, "Cnt_Alignment");
    ui->tabWidget->setTabText(4, "Cooling");
    ui->tabWidget->setTabText(5, "Extracting");

    // connect cmd button execute delta
    connect(ui->execute_delta_subprocess, &QAbstractButton::pressed, [this]() {
        sinkControll.on_execute_delta_subprocess_clicked();
        });
    // connect cmd button execute delta
    connect(ui->run_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.on_run_sinking_process_clicked();
        });

    //connect(&distance, &controller::valueChanged, [this]() {
    //    auto value = distance.getValue();
    //    qInfo() << "value distance controller changed, new value: " << value;
    //    qInfo() << "updating display with thread: " << QThread::currentThread();
    //    ui->lcdNumber_3->display(value);
    //    });
    //auto dis = QtConcurrent::run(&controller::generateValues, &distance);

}

MainWindow::~MainWindow()
{

    delete ui;
}


