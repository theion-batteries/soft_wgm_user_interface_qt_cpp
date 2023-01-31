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
#include <QtConcurrent>
// mvc
#include <atomic>
#include "extractingModel.h"
class extractingController : public QObject
{
    Q_OBJECT
public:
    extractingController(/* args */);
    ~extractingController();
signals:
    void pressed();
    void triggered();
    void returnPressed(); // line edit enter key pressed
    void valueChanged();
    void finished();
    void axisConnected();
    void sensorConnected();
    void axisReplied(std::string reply);
public slots:
    void on_sink_connect_motion_axis_clicked();
    void on_sink_connect_distance_sensor_clicked();
    void on_run_extracting_process_clicked();
    void on_stop_extracting_process_clicked();
    void on_move_down_until_sensor_data_valid_clicked();
    void on_move_down_to_surface_contact_clicked();
    void on_deep_wafer_holder_desired_thickness_clicked();
    void on_monitor_and_calibrate_clicked();


    bool get_axis_status();
    bool get_sensor_status();
    bool getProcessStatus();
    std::string sendAxisCmd(std::string Cmd);
    void reload_whs_config_file();
    // update simple
    // lcd update
    void updateLcdTime(QLCDNumber* Lcd);
    void updateLcdDistance(QLCDNumber* Lcd);
    void updateLcdPosition(QLCDNumber* Lcd);
    // label update
    void updateLabelAxis(QLabel* label);
    void updateLabelSensor(QLabel* label);
    void updateLabelProcess(QLabel* label);
    void updateLabelAxisResponse(QLabel* label, QString cmd);
private:
    extractingModel* extractModel;
    double time_elapsed;

};