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
#include <QObject>
#include <QTConcurrent>

#include "./ui_mainwindow.h"
// mvc
#include "heatingController.h"

class heatingView: public QObject
{
    Q_OBJECT
public:
    heatingView(Ui::MainWindow* uiPtr);
    ~heatingView();
    heatingController* getController();
private:
    Ui::MainWindow* ui;
    heatingController heatControll;
};




