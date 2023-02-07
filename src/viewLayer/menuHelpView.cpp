#include "menuHelpView.h"

menuHelpView::menuHelpView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    /**************** signals and slots ********************/

    // create new user
    connect(ui->actionuser_manual, &QAction::triggered, [this]() {
        on_actionuser_manual_triggered();
        });
    // login
    connect(ui->actiondevelopper_docs, &QAction::triggered, [this]() {
        on_actiondevelopper_docs_triggered();
        });
    // logout
    connect(ui->actioncheck_update, &QAction::triggered, [this]() {
        on_actioncheck_update_triggered();
        });

}
menuHelpView::~menuHelpView()
{
}



void  menuHelpView::on_actionuser_manual_triggered()
{
    QString  link = "https://github.com/theion-batteries/soft_wgm_installer_update/blob/dev_win_api/wgm_application_user_manual.pdf";
    std::cout << "opening user manual inside browser " <<std::endl;
    userManualProc.start("cmd", QStringList() << "/c" << "start" << link);
    
}

void  menuHelpView::on_actiondevelopper_docs_triggered()
{
    QString  link = "https://theionsami.github.io/soft_wgm_user_interface_qt_cpp/html/index.html";
    std::cout << "opening developper documentation inside browser "<<std::endl;
    developpersDocsProc.start("cmd", QStringList() << "/c" << "start" << link);


}

void  menuHelpView::on_actioncheck_update_triggered()
{
    QString  link = "https://github.com/theionSami/soft_wgm_user_interface_qt_cpp/releases";
    std::cout << "checking latest update inside browser " <<std::endl;
    checkUpdateProc.start("cmd", QStringList() << "/c" << "start" << link);
    
}
