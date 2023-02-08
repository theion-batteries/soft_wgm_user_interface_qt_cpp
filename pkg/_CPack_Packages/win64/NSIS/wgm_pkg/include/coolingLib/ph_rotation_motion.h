/**
 * @file Iaxis_motion.h
 * @author sami dhiab
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "sockpp/socket.h"
#include <iostream>
#include <string>
#include "sockpp/tcp_connector.h"
#include "Windows.h" 
#include <shellapi.h> 
#include <map>
#include <thread>
#include <atomic>
#include <queue>
#include <future>
#include "Iph_axis_motion.h"

struct ph_rotation_motion_server
{
    const char* ip = "192.168.0.205";
    uint16_t port = 8881;
};


class ph_rotation_motion: public Iph_axis_motion
{
private:
  ph_rotation_motion_server _rotation_motion_struct;
    sockpp::socket_initializer sockInit;
    sockpp::tcp_connector* axis_client_sock=nullptr;
    bool axisReady = false;
protected:
    std::map<u_int, std::string> axis_cmds = {
        {0,"$X"}, {1,"?"}, {2,"X160"},
        {3,"$"}, {4,"X"},
        {5,"X"}, {6,"X"},
        {7,"$H"}
    };
    std::deque<double> axis_last_position; // FIFO last 10 values
    std::string axis_incoming_data;
    size_t axis_data_length = 1024;
public:
    ph_rotation_motion();
    virtual ~ph_rotation_motion();
    virtual void move_home() override;
    virtual void move_to(int new_position) override;
    void rotate_to(double new_pos) override;
    virtual wgm_feedbacks::enum_sub_sys_feedback connect()override;
    virtual void disconnect() override;
    double get_position() override;
    void get_speed() override;
    void set_speed(double_t new_val) override;
    void move_up_to(double_t new_pos) override;
    void move_down_to(double_t new_pos) override;
    void move_up_by(double_t steps) override;
    void move_down_by(double_t steps) override;
    virtual bool getStatus() override;
    virtual std::string sendDirectCmd(std::string cmd) override;
    std::string waitForResponse();
    void move_center();
    void unlock();
};

















