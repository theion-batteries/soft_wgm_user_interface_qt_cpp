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
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include <QInputDialog>
#include <QDir>
// mvc
#include <iostream>
#include "wgm_user.h"
class menuFileView : public QObject
{
    Q_OBJECT
public:
    menuFileView(Ui::MainWindow* uiPtr);
    ~menuFileView();
signals:
    void triggered();
    void finished();
private:
    Ui::MainWindow* ui;
   

public slots:
    void on_actionnew_user_triggered();
    void on_actionlogin_triggered();
    void on_actionlogout_triggered();

};




