#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->dial_3, &QDial:: valueChanged, [this](){
        auto value = ui->dial_3->value();
        ui->lcdNumber_3->display(value);
    });
    connect(&distance, &controller::valueChanged, [this](){
        auto value = distance.getValue();
        qInfo() <<"value distance controller changed, new value: "<<value;
        qInfo() << "updating display with thread: " << QThread::currentThread();
        ui->lcdNumber_3 ->display(value);
    });
    auto dis = QtConcurrent::run(&controller::generateValues, &distance);




    // kill threads on app exit
    connect(ui->dial, &QDial:: valueChanged, [this](){
        auto value = ui->dial->value();
        ui->lcdNumber->display(value);
    });
    connect(ui->dial_3, &QDial:: valueChanged, [this](){
        auto value = ui->dial_3->value();
        ui->lcdNumber_3->display(value);
    });
}

MainWindow::~MainWindow()
{

    delete ui;
}

