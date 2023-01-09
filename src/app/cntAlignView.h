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
#include "cntAlignController.h"

class cntAlignView: public QObject
{
   // Q_OBJECT
public:
    cntAlignView(Ui::MainWindow* uiPtr);
    ~cntAlignView();
    cntAlignController* getController();

private:
    Ui::MainWindow* ui;
    cntAlignController cntControll ;

};




