/**
 * @file process_manager.h
 * @author sami dhiab (sami@theion.de)
 * @brief process management package
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "Iprocess_manager.h"
using enum wgm_feedbacks::enum_sys_feedback;
using enum wgm_feedbacks::enum_proc_feedback;

namespace wgm_processes
{

    /****************** interface cooling process *******************/
    class Icooling_process: public Iprocess_manager
    {
    public:
        Icooling_process();
        virtual ~Icooling_process();
        virtual wgm_feedbacks::enum_proc_feedback start_process() = 0;
        virtual wgm_feedbacks::enum_proc_feedback stop_process() = 0;
        virtual std::string get_name() = 0;
        virtual int get_id() = 0;
        virtual bool is_proc_success() = 0;
        virtual wafer_cooling_system::Icooling_controller* get_sys_ptr() = 0;
        virtual long long get_elapsed_time() = 0;
    };
    /******************* implementation cooling process ***************/
    class cooling_process: public Icooling_process
    {
    private:
        wgm_feedbacks::proc_feedback process_feedback;
        wgm_monitoring::Itime_monitor* process_timer;
        wafer_cooling_system::Icooling_controller* cooling_sys;
        std::string process_name = "Cooling";
        int proc_id = 3;

    public:
        cooling_process();
        virtual ~cooling_process();
        virtual wgm_feedbacks::enum_proc_feedback start_process();
        virtual wgm_feedbacks::enum_proc_feedback stop_process();
        virtual std::string get_name();
        virtual bool is_proc_success();
        virtual wafer_cooling_system::Icooling_controller* get_sys_ptr();
        virtual long long get_elapsed_time();
        virtual int get_id(){return proc_id;};


    };

}


