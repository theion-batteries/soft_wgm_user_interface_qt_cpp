#include "menuFileView.h"

menuFileView::menuFileView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    /**************** signals and slots ********************/
         // open whs config
    connect(ui->actionwhs_config, &QAction::triggered, [this]() {
        on_actionwhs_config_triggered();
        });
    // create new user
    connect(ui->actionnew_user, &QAction::triggered, [this]() {
        on_actionnew_user_triggered();
        });
}

menuFileView::~menuFileView()
{
}

void  menuFileView::on_actionwhs_config_triggered()
{
#ifdef WHS_CONFIG
    std::cout << "opening whs config yaml file in notepad" << std::endl;
    whs_config_editor.start("C:\\Windows\\system32\\notepad.exe", { WHS_CONFIG });
#endif
}

QProcess* menuFileView::getWhsConfigProc()
{
    return &whs_config_editor;
}

void menuFileView::on_actionnew_user_triggered()
{
//QMessageBox msgBox;
//QLineEdit username;
//QLineEdit password;
//username.setText("enter username");
//password.setText("enter password");
//msgBox.layout()->addWidget(&username);
//msgBox.layout()->addWidget(&password);
//
//int ret = msgBox.exec();
        QMessageBox msgbox;
        msgbox.setText("to select click");
        msgbox.setDetailedText("line 1\nline 2\nline 3");
        msgbox.exec();
}
