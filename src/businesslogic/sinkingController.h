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
#include "sinkingModel.h"
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
    void on_connect_keyence_sensor_clicked();
    void on_run_sinking_process_clicked();
    void on_stop_sinking_process_clicked();
    void on_actionwhs_config_triggered(); 
    QString get_delta_status();
    

    // view distance sensors


private:
    sinkingModel proc_sinking_model;
    double time_elapsed;
    QLCDNumber* LcdTime;
    QLCDNumber* LcdDistance;

};