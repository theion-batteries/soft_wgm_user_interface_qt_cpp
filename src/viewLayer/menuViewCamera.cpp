#include "menuViewCamera.h"

menuViewCamera::menuViewCamera(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    /**************** signals and slots ********************/

    // 
    connect(ui->actionuser_manual, &QAction::triggered, [this]() {
        on_actionuser_manual_triggered();
        });
    // 
    connect(ui->actiondevelopper_docs, &QAction::triggered, [this]() {
        on_actiondevelopper_docs_triggered();
        });
    // 
    connect(ui->actioncheck_update, &QAction::triggered, [this]() {
        on_actioncheck_update_triggered();
        });
    // 
    connect(ui->actionMeteor_docs, &QAction::triggered, [this]() {
        on_actionMeteor_docs_triggered();
        });
}
menuViewCamera::~menuViewCamera()
{
}



void  menuViewCamera::on_actionuser_manual_triggered()
{
    QString  link = "https://github.com/theion-batteries/soft_wgm_installer_update/blob/dev_win_api/wgm_application_user_manual.pdf";
    std::cout << "opening user manual inside browser " <<std::endl;
    userManualProc.start("cmd", QStringList() << "/c" << "start" << link);
    
}

void  menuViewCamera::on_actiondevelopper_docs_triggered()
{
    QString  link = "https://theionsami.github.io/soft_wgm_user_interface_qt_cpp/html/index.html";
    std::cout << "opening developper documentation inside browser "<<std::endl;
    developpersDocsProc.start("cmd", QStringList() << "/c" << "start" << link);


}

void  menuViewCamera::on_actioncheck_update_triggered()
{
    QString  link = "https://github.com/theionSami/soft_wgm_user_interface_qt_cpp/releases";
    std::cout << "checking latest update inside browser " <<std::endl;
    checkUpdateProc.start("cmd", QStringList() << "/c" << "start" << link);
    
}
void  menuViewCamera::on_actionMeteor_docs_triggered()
{
    QString  path = "C:/Program Files/Meteor Inkjet/Meteor/Doc/PrinterInterfaceCLS.chm";
    std::cout << "openin meteor documentation " <<std::endl;
QProcess::startDetached("hh.exe", QStringList() << path);    
}
