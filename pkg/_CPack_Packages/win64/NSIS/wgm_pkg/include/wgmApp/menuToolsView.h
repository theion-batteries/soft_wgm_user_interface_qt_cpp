/**
 * @file view.h
 * @author sami dhiab
 * @brief template for view layer
 * @version 0.1
 * @date 2022-10-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
// qt
#include "./ui_mainwindow.h"
#include <QProcess>
#include <QObject>
#include <QString>

// mvc
#include <iostream>
class menuToolsView : public QObject
{
    Q_OBJECT
public:
    menuToolsView(Ui::MainWindow* uiPtr);
    ~menuToolsView();
signals:
    void triggered();
    void finished();
private:
    Ui::MainWindow* ui;

public slots:
    void on_actionopen_MeteorPrintEngine_triggered();
    void on_actionopen_MetDrop_triggered();
    void on_actionopen_MetSim_triggered();
    void on_actionopen_MetViewer_triggered();
    void on_actionopen_MetViewer_server_triggered();
    void on_actionopen_MeteorMonoPrint_triggered();
    void on_actionopen_PrintEngineHost_triggered();
    void on_actionopen_TestApp_triggered();
    void on_actionopen_MetPrint_triggered();


};




