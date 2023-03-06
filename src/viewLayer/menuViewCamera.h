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
#include <QString>

// mvc
#include <iostream>
class menuHelpView : public QObject
{
    Q_OBJECT
public:
    menuHelpView(Ui::MainWindow* uiPtr);
    ~menuHelpView();
signals:
    void triggered();
    void finished();
private:
    Ui::MainWindow* ui;
    QProcess userManualProc;
    QProcess developpersDocsProc;
    QProcess checkUpdateProc;

public slots:
    void on_actionuser_manual_triggered();
    void on_actiondevelopper_docs_triggered();
    void on_actioncheck_update_triggered();
    void on_actionMeteor_docs_triggered();


};




