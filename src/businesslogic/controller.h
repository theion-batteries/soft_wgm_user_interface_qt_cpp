#pragma once 
#include <random>
#include <QObject>
#include <iostream>
#include <QDebug>
#include <QThread>
#include <atomic>
#include "model.h"

class controller: public QObject
{
    Q_OBJECT
    int m_value=0;
    std::atomic_bool exit_flag=false;
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
