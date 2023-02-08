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
#include <QProcess>
// mvc
#include "mainController.h"
// Cpp program to redirect cout to a file
#include <fstream>
#include <iostream>
#include <string>

class menuDebugView: public QObject
{
    Q_OBJECT
public:
    menuDebugView(Ui::MainWindow* uiPtr);
    ~menuDebugView();
signals:
    void triggered();
public slots:
    void on_actionopen_debug_console_triggered(); 
private:
    Ui::MainWindow* ui;


    
};




