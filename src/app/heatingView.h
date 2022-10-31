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

class heatingView: QObject
{
    Q_OBJECT
public:
    heatingView(Ui::MainWindow* uiPtr);
    ~heatingView();
private:
    Ui::MainWindow* ui;
};




