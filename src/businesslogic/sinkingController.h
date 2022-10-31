#pragma once 
// 
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
    void on_connect_delta_clicked();
    void on_connect_keyence_sensor_clicked();
    void on_run_sinking_process_clicked();
    void on_stop_sinking_process_clicked();
    void on_actionwhs_config_triggered(); 
    QString get_delta_status();
    

    // view distance sensors


private:
    modelSinking proc_sinking_model;
    double time_elapsed;
    QLCDNumber* LcdTime;
    QLCDNumber* LcdDistance;

};