#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /********** General UI Setup*********************/
    ui->setupUi(this);
    setWindowTitle("Wafer Growing System User Interface");
    /********** menu View *********************/
    fileView = new menuFileView(getUi());
    editView = new menuEditView(getUi());
    debugView = new menuDebugView(getUi());
    helpView = new menuHelpView(getUi());
    toolsView = new menuToolsView(getUi());
    /********** process Tab View *********************/
    managerView = new mainView(getUi());
    sinkView = new sinkingView(getUi());
    heatView = new heatingView(getUi());
    cntView = new cntAlignView(getUi());
    extractView = new extractingView(getUi());
    coolView = new coolingView(getUi());

    /********************* connect tab with menu **************************/
    connect(editView->getWhsConfigProc(), &QProcess::finished,
        [this]() {
            std::cout<<"process exit succefully"<<"\n";
            sinkView->getController()->reload_whs_config_file();
         });

    /********************* connect tab with menu **************************/
    connect(editView->getCntConfigProc(), &QProcess::finished,
        [this]() {
            std::cout<<"process exit succefully"<<"\n";
            cntView->getController()->reload_cnt_config_file();
         });
  /********************* connect tab with menu **************************/
    connect(editView->getPhConfigProc(), &QProcess::finished,
        [this]() {
            std::cout<<"process exit succefully"<<"\n";
            coolView->getController()->reload_ph_config_file();
         });
  /********************* connect tab with menu **************************/
    connect(editView->getHeatConfigProc(), &QProcess::finished,
        [this]() {
            std::cout<<"process exit succefully"<<"\n";
            heatView->getController()->reload_heating_config_file();
         });
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

