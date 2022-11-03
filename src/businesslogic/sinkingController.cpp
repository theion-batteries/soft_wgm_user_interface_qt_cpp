#include "sinkingController.h"

/***************** Sinking controller *******************/

sinkingController::sinkingController()
{
    std::cout << "sinking controller constructed" << std::endl;
}

sinkingController::~sinkingController()
{
    std::cout << "sinking controller desctructed" << std::endl;
}

void sinkingController::on_sink_connect_distance_sensor_clicked()
{
    proc_sinking_model.sinkingProcessHandler->get_sys_ptr()->connect_sensor();
}

void sinkingController::on_sink_connect_motion_axis_clicked()
{
    proc_sinking_model.sinkingProcessHandler->get_sys_ptr()->connect_sensor();
}

void sinkingController::on_run_sinking_process_clicked()
{
    LcdTime->display(time_elapsed);
    proc_sinking_model.sinkingProcessHandler->start_process();
    time_elapsed = proc_sinking_model.sinkingProcessHandler->get_elapsed_time();
}

void sinkingController::on_stop_sinking_process_clicked()
{
    LcdTime->display(time_elapsed);
    proc_sinking_model.sinkingProcessHandler->stop_process();
    time_elapsed = proc_sinking_model.sinkingProcessHandler->get_elapsed_time();
}
void sinkingController::passLcdNum(QLCDNumber* Lcd)
{
    LcdTime = Lcd;
    LcdTime->display(time_elapsed);
    time_elapsed = 0;
}


QString sinkingController::get_axis_status()
{

    std::cout<<proc_sinking_model.sinkingProcessHandler->get_sys_ptr()->getSubSysStatus("axis_motion")<<std::endl;
    if (proc_sinking_model.sinkingProcessHandler->get_sys_ptr()->getSubSysStatus("axis_motion") == true) return "true";
    else return "false";
}

QString sinkingController::get_sensor_status()
{

    std::cout<<proc_sinking_model.sinkingProcessHandler->get_sys_ptr()->getSubSysStatus("axis_motion")<<std::endl;
    if (proc_sinking_model.sinkingProcessHandler->get_sys_ptr()->getSubSysStatus("axis_motion") == true) return "true";
    else return "false";
}