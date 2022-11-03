#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /********** General UI Setup*********************/
    ui->setupUi(this);
    /********** menu View *********************/
    editView= new menuEditView(getUi());
    debugView= new menuDebugView(getUi());
    /********** process Tab View *********************/
    managerView = new mainView(getUi());
    sinkView = new sinkingView(getUi());
    heatView = new heatingView(getUi());
    cntView = new cntAlignView(getUi());
    extractView = new extractingView(getUi());
     
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
    delete managerView;
    delete sinkView;
    delete heatView;
    delete cntView;
    delete extractView;
    delete ui;
}
Ui::MainWindow* MainWindow::getUi()
{
    return ui;
}

