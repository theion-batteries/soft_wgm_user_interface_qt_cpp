#pragma once 
#include <random>
#include <QObject>
#include <iostream>
#include <QDebug>
#include <QThread>
#include <atomic>
class sensor: public QObject
{
    Q_OBJECT
    int m_value=0;
    std::atomic_bool exit_flag=false;
public:
    sensor(/* args */);
    ~sensor();

public slots:
    void generateValues();
    int getValue();
signals:
   void valueChanged(int newValue);

};
