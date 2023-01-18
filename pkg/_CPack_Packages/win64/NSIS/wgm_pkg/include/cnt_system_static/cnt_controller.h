#pragma once
#include "cnt_dispenser_vibration.h"
#include "cnt_linear_motion.h"
#include "cnt_high_voltage_gbs.h"
#include <fstream>
#include "yaml-cpp/yaml.h"
struct cnt_config_yaml_params
{

    double distance_to_center = 50;
    double dispenser_frequency = 10;
    double dispenser_duration = 100;

};
class cnt_controller
{
private:
    std::shared_ptr <Icnt_dispenser> dispenser;
    std::shared_ptr <Icnt_axis_motion> motion;
    std::shared_ptr <Icnt_high_voltage> hv_Dev;
    bool cntReady = false;
    YAML::Node config;
    cnt_config_yaml_params _cnt_params;
public:
    cnt_controller(/* args */);
    ~cnt_controller();
    // controller
    void cnt_controller_connect();

    // motion
    void cnt_motion_connect();
    void cnt_motion_move_home();
    void cnt_motion_move_to_center(double new_pos);
    void cnt_motion_unlock();

    // dispenser
    void cnt_dispenser_connect();
    void cnt_dispenser_activate();
    void cnt_dispenser_deactivate();
    void cnt_dispenser_vibrate();
    void cnt_dispenser_setVibrateDuration(u_int durationSecond);

    // hv
    void cnt_hv_connect();

    /********* helper functions */
    bool get_motion_status();
    bool get_dispenser_status();
    bool get_hv_status();
    bool get_cnt_controller_status();
    double get_center_target_distance();
    /*     helper getter */
    double get_dispenser_frequency();
    double get_axis_position();
    Icnt_axis_motion* get_axis_ptr();
    Icnt_dispenser* get_dispenser_ptr();
    Icnt_high_voltage* get_hv_ptr();
    // direct call
    void sendDirectCmd(std::string& cmd);
    std::string sendDirectCmdAxis(std::string& cmd);
    void reload_config_file();
};


