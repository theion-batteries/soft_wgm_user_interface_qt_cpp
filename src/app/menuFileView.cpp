#include "menuFileView.h"

menuFileView::menuFileView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    /**************** signals and slots ********************/

    // create new user
    connect(ui->actionnew_user, &QAction::triggered, [this]() {
        on_actionnew_user_triggered();
        });
    // login
    connect(ui->actionlogin, &QAction::triggered, [this]() {
        on_actionlogin_triggered();
        });
    // logout
    connect(ui->actionlogout, &QAction::triggered, [this]() {
        on_actionlogout_triggered();
        });
}

menuFileView::~menuFileView()
{
}



QProcess* menuFileView::getWhsConfigProc()
{
    return &whs_config_editor;
}

void menuFileView::on_actionnew_user_triggered()
{
    QMessageBox msgBox;
    bool ok;
    QString username = QInputDialog::getText(&msgBox, tr("create new user"),
        tr("please enter username:"), QLineEdit::Normal,
        NULL, &ok);
    QString password = QInputDialog::getText(&msgBox, tr("create new user"),
        tr("please enter password:"), QLineEdit::Password,
        NULL, &ok);
    wgm_user::user new_user(username.toStdString(), password.toStdString());
    msgBox.setText("added new user to database");
    msgBox.exec();
}


void menuFileView::on_actionlogin_triggered()
{
    QMessageBox msgBox;
    bool ok;
    QString username = QInputDialog::getText(&msgBox, tr("login user"),
        tr("please enter username:"), QLineEdit::Normal,
        NULL, &ok);
    QString password = QInputDialog::getText(&msgBox, tr("create new user"),
        tr("please enter password:"), QLineEdit::Password,
        NULL, &ok);
    // debug
    std::cout << "searching database for matching user and password" << std::endl;
    if (wgm_user::user::login(username.toStdString(), password.toStdString()))
    {
        msgBox.setText("user login success");
        msgBox.exec();
        return;
    }
    msgBox.setText("no user found, please verify username and password or create new user");
        msgBox.exec();

}

void menuFileView::on_actionlogout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("logout user");
    msgBox.exec();

}