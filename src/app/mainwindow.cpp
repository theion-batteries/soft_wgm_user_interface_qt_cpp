#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->dial, &QDial:: valueChanged, [this](){
        auto value = ui->dial->value();
        ui->lcdNumber->display(value);
    });
    connect(ui->dial_3, &QDial:: valueChanged, [this](){
        auto value = ui->dial_3->value();
        ui->lcdNumber_3->display(value);
    });
    connect(&temperature, &sensor::valueChanged, [this](){
        auto value = temperature.getValue();
        qInfo() <<"value temperature sensor changed, new value: "<<value;
        qInfo() << "updating display with thread: " << QThread::currentThread();
        ui->lcdNumber->display(value);
    });
    connect(&distance, &sensor::valueChanged, [this](){
        auto value = distance.getValue();
        qInfo() <<"value distance sensor changed, new value: "<<value;
        qInfo() << "updating display with thread: " << QThread::currentThread();
        ui->lcdNumber_3 ->display(value);
    });
    auto tem = QtConcurrent::run(&sensor::generateValues, &temperature);
    auto dis = QtConcurrent::run(&sensor::generateValues, &distance);




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

