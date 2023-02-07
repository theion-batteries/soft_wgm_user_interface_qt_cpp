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
#include "coolingController.h"
class coolingView: public QObject
{
    //Q_OBJECT
public:
    coolingView(Ui::MainWindow* uiPtr);
    ~coolingView();
    coolingController* getController();

private:
    Ui::MainWindow* ui;
    coolingController coolControll;
};



