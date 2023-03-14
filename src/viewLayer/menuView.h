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
#include <QObject>

// mvc
#include "menuDebugView.h"
#include "menuEditView.h"
#include "menuFileView.h"
#include "menuHelpView.h"
#include "menuToolsView.h"



class menuView: public QObject
{
    Q_OBJECT
public:
    menuView(Ui::MainWindow* uiPtr);
    ~menuView();
private:
    Ui::MainWindow* ui;
signals:
    void triggered();

public slots:
    void on_actionopen_monitor_camera_triggered();

};




