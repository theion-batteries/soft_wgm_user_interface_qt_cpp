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
#include <iostream>
#include <keyence_client.h>
// mvc


class menuDebugView: QObject
{
    Q_OBJECT
public:
    menuDebugView(Ui::MainWindow* uiPtr);
    ~menuDebugView();
signals:
    void triggered();
private:
    Ui::MainWindow* ui;
public slots:
    void on_actionopen_debug_console_triggered(); 

    
};




