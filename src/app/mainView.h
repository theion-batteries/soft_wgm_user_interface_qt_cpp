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

class mainView: QObject
{
    Q_OBJECT
public:
    mainView(Ui::MainWindow* uiPtr);
    ~mainView();
private:
    Ui::MainWindow* ui;
};




