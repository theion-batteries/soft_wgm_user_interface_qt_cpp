#pragma once 
#include <random>
#include <QObject>
#include <iostream>
#include <QDebug>
#include <QThread>
#include <atomic>
#include "model.h"
//#include <QAbstractButton>

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
signals:
    void pressed();
public slots:
    void on_execute_delta_subprocess_clicked();
    void on_run_sinking_process_clicked();

    
private:
    modelSinking proc_sinking_model;

};