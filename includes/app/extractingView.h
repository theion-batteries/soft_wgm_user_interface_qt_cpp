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
// mvc

class extractingView: public QObject
{
    Q_OBJECT
public:
    extractingView(Ui::MainWindow* uiPtr);
    ~extractingView();
private:
    Ui::MainWindow* ui;
};




