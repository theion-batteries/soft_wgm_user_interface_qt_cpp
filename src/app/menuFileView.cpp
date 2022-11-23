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
QMessageBox msgBox;
    bool ok;
    QInputDialog userInput;
   // userInput.getMultiLineText()
    QString username = QInputDialog::getText(&msgBox, tr("create new user"),
                                         tr("please enter username:"), QLineEdit::Normal,
                                         NULL, &ok);
    QString password = QInputDialog::getText(&msgBox, tr("create new user"),
                                         tr("please enter password:"), QLineEdit::Password,
                                         NULL, &ok);                
    //debug
    std::cout << "username: " << username.toStdString() << " password: "<< password.toStdString() <<std::endl;
    wgm_user::user new_user(username.toStdString(),password.toStdString());
    userList.push_back(new_user);
    // debug
    std::cout<<"added new user to list"<<std::endl;
    std::cout<<"listing available users"<<std::endl;
    for(auto& u: userList)
    {
    std::cout << "username: " << u.getUserName() << " password: "<< u.getUserPassowrd() <<std::endl;
    }
}
