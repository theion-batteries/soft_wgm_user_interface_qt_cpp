/**
 * @file controller.h
 * @author sami dhiab
 * @brief template for control layer mvc
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once 
#include <random>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QLCDNumber>
#include <QFile>
#include <QProcess>
#include <QLabel>
#include <QString>
//
#include <atomic>
#include "model.h"

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
