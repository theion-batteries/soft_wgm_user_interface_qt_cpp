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
#include "sinkingController.h"

class sinkingView: public QObject
{
    //Q_OBJECT
public:
    sinkingView(Ui::MainWindow* uiPtr);
    ~sinkingView();
    sinkingController* getController();
private:
    Ui::MainWindow* ui;
    sinkingController sinkControll;
};




