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
// mvc
#include <iostream>

class menuEditView: public QObject
{
    Q_OBJECT
public:
    menuEditView(Ui::MainWindow* uiPtr);
    ~menuEditView();
signals:
    void triggered();
    void finished();
private:
    Ui::MainWindow* ui;
    QProcess whs_config_editor;

public slots:
    void on_actionwhs_config_triggered(); 
    QProcess* getWhsConfigProc();
};




