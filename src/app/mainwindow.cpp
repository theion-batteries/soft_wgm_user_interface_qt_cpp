#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /********** General UI Setup*********************/
    ui->setupUi(this);

    ui->tabWidget->setTabText(0, "Main");
    ui->tabWidget->setTabText(1, "Heating");
    ui->tabWidget->setTabText(3, "Cnt_Alignment");
    ui->tabWidget->setTabText(4, "Cooling");
    ui->tabWidget->setTabText(5, "Extracting");
    /********** Sinking View *********************/
    sinkView = new sinkingView(getUi());

   // connect(&sinkControll, &sinkingController::valueChanged, [this]() {
   //     auto value = distance.getValue();
   //     qInfo() << "value distance controller changed, new value: " << value;
   //     qInfo() << "updating display with thread: " << QThread::currentThread();
   //   ui->temperature->display(value);
   //     });
   // auto dis = QtConcurrent::run(&controller::generateValues, &distance);

}

MainWindow::~MainWindow()
{
    delete sinkView;
    delete ui;
}
Ui::MainWindow* MainWindow::getUi()
{
    return ui;
}

