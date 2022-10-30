#pragma once 
#include <random>
#include <QObject>
#include <iostream>
#include <QDebug>
#include <QThread>
#include <QLCDNumber>
#include <atomic>
#include "model.h"
#include <QFile>
#include <QProcess>

class controller : public QObject
{
    Q_OBJECT
        int m_value = 0;
    std::atomic_bool exit_flag = false;
public:
    controller(/* args */);
    ~controller();

public slots:
    void generateValues();
    int getValue();
signals:
    void valueChanged(int newValue);

private:
    model proc_model;
};

class processController : public QObject
{};

class sinkingController : public QObject
{
    Q_OBJECT
public:
    sinkingController(/* args */);
    ~sinkingController();
    void passLcdNum(QLCDNumber* Lcd);
signals:
    void pressed();
    void triggered();
public slots:
    void on_execute_delta_subprocess_clicked();
    void on_run_sinking_process_clicked();
    void on_stop_sinking_process_clicked();
    void on_actionwhs_config_triggered(); 
private:
    modelSinking proc_sinking_model;
    double time_elapsed;
    QLCDNumber* LcdTime;
    QLCDNumber* LcdDistance;

};