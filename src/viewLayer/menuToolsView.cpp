#include "menuToolsView.h"

menuToolsView::menuToolsView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    /**************** signals and slots ********************/

    // open meteor Engine
    connect(ui->actionopen_MeteorPrintEngine, &QAction::triggered, [this]() {
        on_actionopen_MeteorPrintEngine_triggered();
        });
    connect(ui->actionopen_MetDrop, &QAction::triggered, [this]() {
        on_actionopen_MetDrop_triggered();
        });
    connect(ui->actionopen_MetSim, &QAction::triggered, [this]() {
        on_actionopen_MetSim_triggered();
        });
    connect(ui->actionopen_MetViewer, &QAction::triggered, [this]() {
        on_actionopen_MetViewer_triggered();
        });
    connect(ui->actionopen_MetViewerServer, &QAction::triggered, [this]() {
        on_actionopen_MetViewer_server_triggered();
        });
    connect(ui->actionopen_MeteorMonoPrint, &QAction::triggered, [this]() {
        on_actionopen_MeteorMonoPrint_triggered();
        });
    connect(ui->actionopen_PrintEngineHost, &QAction::triggered, [this]() {
        on_actionopen_PrintEngineHost_triggered();
        });
    connect(ui->actionopen_TestApp, &QAction::triggered, [this]() {
        on_actionopen_TestApp_triggered();
        });
    connect(ui->actionopen_MetPrint, &QAction::triggered, [this]() {
        on_actionopen_MetPrint_triggered();
        });
}
menuToolsView::~menuToolsView()
{
}


void  menuToolsView::on_actionopen_MeteorPrintEngine_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/Monitor.exe";
    QProcess::startDetached(path);
    std::cout << "Opening Meteor PrintEngine" << std::endl;
}
void  menuToolsView::on_actionopen_MetDrop_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/MetDrop/MetDrop.exe";
    QProcess::startDetached(path);
    std::cout << "Opening MetDrop " << std::endl;
}
void  menuToolsView::on_actionopen_MetSim_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/SimPrint/SimPrint.exe";
    QProcess::startDetached(path);
    std::cout << "Opening MetSim " << std::endl;
}
void  menuToolsView::on_actionopen_MetViewer_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/MetViewer/MetViewer.exe";
    QProcess::startDetached(path);
    std::cout << "Opening MetViewer " << std::endl;
}
void  menuToolsView::on_actionopen_MetViewer_server_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/Metdrop/MetViewerServer.exe";
    QProcess::startDetached(path);
    std::cout << "Opening MetViewer " << std::endl;
}

void  menuToolsView::on_actionopen_MeteorMonoPrint_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/Api/amd64/MeteorMonoPrint.exe";
    QProcess::startDetached(path);
    std::cout << "Opening MonoPrint " << std::endl;
}
void  menuToolsView::on_actionopen_PrintEngineHost_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/Api/amd64/PrintEngineHost.exe";
    QProcess::startDetached(path);
    std::cout << "Opening PrintEngineHost" << std::endl;
}

void  menuToolsView::on_actionopen_TestApp_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/TestApp/TestApp.exe";
    QProcess::startDetached(path);
    std::cout << "Opening TestApp" << std::endl;
}

void  menuToolsView::on_actionopen_MetPrint_triggered()
{
    QString path = "C:/Program Files/Meteor Inkjet/Meteor/DFE/MetPrint/MetPrint.exe";
    QProcess::startDetached(path);
    std::cout << "Opening MetPrint" << std::endl;
}