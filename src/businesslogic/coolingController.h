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
#include "coolingModel.h"
class coolingController : public QObject
{
    Q_OBJECT
public:
    coolingController(/* args */);
    ~coolingController();
signals:
    void pressed();
    void triggered();
    void returnPressed(); // line edit enter key pressed
    void valueChanged();
    void finished();
    void axisConnected();
    void rotationConnected();
    void phConnected();
    void axisReplied(std::string reply);
    void rotaryReplied(std::string reply);
    void phReplied(std::string reply);
public slots:
    void on_connect_motion_axis_ph_clicked();
    void on_connect_rotation_axis_ph_clicked();
    void on_connect_ph_clicked();
    void on_run_cooling_process_clicked();
    void on_stop_cooling_process_clicked();
    void on_ph_move_center_clicked();
    void on_linear_move_home_clicked();
    void on_rotation_move_home_clicked();
    void on_ph_print_clicked();


    bool get_axis_status();
    bool get_rotary_status();
    bool get_ph_status();
    bool getProcessStatus();
    std::string sendAxisCmd(std::string Cmd);
    void reload_ph_config_file();
    // update simple
    // lcd update
    void updateLcdTime(QLCDNumber* Lcd);
    void updateLcdRotationPosition(QLCDNumber* Lcd);
    void updateLcdAxisPosition(QLCDNumber* Lcd);
    void updateLcdPhFrequency(QLCDNumber* Lcd);


    
    // label update
    void updateLabelAxis(QLabel* label);
    void updateLabelRotation(QLabel* label);
    void updateLabelPh(QLabel* label);
    void updateLabelProcess(QLabel* label);
    void updateLabelAxisResponse(QLabel* label, QString cmd);
    void updateLabelRotResponse(QLabel* label, QString cmd);
    void updateLabelPhResponse(QLabel* label, QString cmd);
private:
    coolingModel coolModel;
    double time_elapsed;

};