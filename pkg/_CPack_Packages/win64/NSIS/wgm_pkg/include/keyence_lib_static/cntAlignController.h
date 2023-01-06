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
#include "cntAlignModel.h"
class cntAlignController : public QObject
{
   // Q_OBJECT
public:
    cntAlignController(/* args */);
    ~cntAlignController();
signals:
    void pressed();
    void triggered();
    void returnPressed(); // line edit enter key pressed
    void valueChanged();
public slots:
    void on_cnt_connect_motion_axis_clicked();
    void on_cnt_connect_dispenser_clicked();
    void on_cnt_connect_hv_clicked();
    void on_run_cnt_aligning_process_clicked();
    void on_stop_cnt_proc_clicked();
    void on_move_down_to_center_clicked();
    void on_move_back_home_clicked();
    void on_dispenser_vibrate_clicked();
    void on_high_voltage_pulse_clicked();


    bool get_axis_status();
    bool get_dispenser_status();
    bool get_hv_status();
    bool getProcessStatus();
    std::string sendAxisCmd(std::string Cmd);
    void reload_cnt_config_file();
    // update simple
    // lcd update
    void updateLcdTime(QLCDNumber* Lcd);
    void updateLcdDispenserFreq(QLCDNumber* Lcd);
    void updateLcdPosition(QLCDNumber* Lcd);
    void updateLcdInputVoltage(QLCDNumber* Lcd);
    void updateLcdOutputVoltage(QLCDNumber* Lcd);
    void updateLcdInputCurrent(QLCDNumber* Lcd);
    void updateLcdOutputCurrent(QLCDNumber* Lcd);
    void updateLcdInputFrequency(QLCDNumber* Lcd);
    void updateLcdOutputFrequency(QLCDNumber* Lcd);
    // label update
    void updateLabelAxis(QLabel* label);
    void updateLabelDispenser(QLabel* label);
    void updateLabelHV(QLabel* label);
    void updateLabelProcess(QLabel* label);
    void updateLabelAxisResponse(QLabel* label, QString cmd);

private:
    cntAlignModel cntModel;
    double time_elapsed;
    
};