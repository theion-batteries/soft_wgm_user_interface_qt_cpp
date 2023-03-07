#include "menuView.h"

menuView::menuView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    /**************** signals and slots ********************/
         // 
    connect(ui->actionopen_monitor_camera, &QAction::triggered, [this]() {
        on_actionopen_monitor_camera_triggered();
        });
}

menuView::~menuView()
{
}

void  menuView::on_actionopen_monitor_camera_triggered()
{
    QString  path = "C:/Program Files/wgm_pkg/utils/camStream.exe";
    std::cout << "starting camera stream " << std::endl;
    QProcess::startDetached(path, QStringList());
}
