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
#include <QtConcurrent>

#include "./ui_mainwindow.h"
// mvc
#include "extractingController.h"
class extractingView: public QObject
{
    Q_OBJECT
public:
    extractingView(Ui::MainWindow* uiPtr);
    ~extractingView();
        extractingController* getController();

private:
    Ui::MainWindow* ui;
    extractingController extractControll;
};




