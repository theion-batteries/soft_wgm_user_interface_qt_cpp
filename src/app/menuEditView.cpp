#include "menuEditView.h"

menuEditView::menuEditView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
/**************** signals and slots ********************/
     // open whs config
    connect(ui->actionwhs_config, &QAction::triggered, [this]() {
        on_actionwhs_config_triggered();
        });
}

menuEditView::~menuEditView()
{
}

void  menuEditView::on_actionwhs_config_triggered()
{
#ifdef WHS_CONFIG
    std::cout<< "opening whs config yaml file in notepad"<<std::endl;
    QProcess::startDetached("C:\\Windows\\system32\\notepad.exe", {WHS_CONFIG});
#endif
}