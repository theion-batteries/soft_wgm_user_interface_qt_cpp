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
#include "menuView.h"
#include "sinkingView.h"
#include "cntAlignView.h"
#include "coolingView.h"
#include "heatingView.h"
#include "extractingView.h"
#include "mainView.h"

class processTabView: QObject
{
    Q_OBJECT
public:
    processTabView(Ui::MainWindow* uiPtr);
    ~processTabView();
private:
    Ui::MainWindow* ui;
};




