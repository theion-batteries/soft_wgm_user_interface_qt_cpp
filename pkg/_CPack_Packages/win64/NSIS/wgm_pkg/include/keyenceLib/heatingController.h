#pragma once 
// qt
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QLCDNumber>
#include <QFile>
#include <QProcess>
#include <QLabel>
#include <QString>
// mvc
#include <atomic>
#include "heatingModel.h"
class heatingController: public QObject
{
    Q_OBJECT
public:
    heatingController(/* args */);
    ~heatingController();
signals:
    void pressed();
    void triggered();
    void returnPressed(); // line edit enter key pressed
    void valueChanged();
    void finished();
    void heaterConnected();
    void heaterReplied(std::string reply);

public slots:
    void on_connect_heating_dev_clicked();
    void on_run_heating_process_clicked();
    void on_stop_heating_proc_clicked();
    void on_start_heating_clicked();
    void on_stop_heating_clicked();
    bool get_heating_status();
    bool getProcessStatus();
    std::string sendDirectCmd(std::string Cmd);
    void reload_heating_config_file();
    // update simple
    // lcd update
    void updateLcdTime(QLCDNumber* Lcd);
    void updateLcdTemperature(QLCDNumber* Lcd);
    // label update
    void updateLabelHeater(QLabel* label);
    void updateLabelProcess(QLabel* label);
    // response update
    void updateLabelHeaterResponse(QLabel* label, QString cmd);


private:
    heatingModel heatModel;
    double time_elapsed;

};