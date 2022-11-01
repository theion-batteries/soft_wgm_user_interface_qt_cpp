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

void sinkingController::on_connect_distance_sensor_clicked()
{
    proc_sinking_model.sinkingProcessHandler->get_sys_obj()->connect_keyence();
}

void sinkingController::on_connect_motion_axis_clicked()
{
    proc_sinking_model.sinkingProcessHandler->get_sys_obj()->connect_keyence();
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

void  sinkingController::on_actionwhs_config_triggered()
{
#ifdef WHS_CONFIG
    qInfo() << "opening whs config yaml file in notepad";
    QProcess::startDetached("C:\\Windows\\system32\\notepad.exe", {WHS_CONFIG});
#endif

}
QString sinkingController::get_axis_status()
{

    std::cout<<proc_sinking_model.sinkingProcessHandler->get_sys_obj()->getSubSysStatus("delta")<<std::endl;
    if (proc_sinking_model.sinkingProcessHandler->get_sys_obj()->getSubSysStatus("delta") == true) return "true";
    else return "false";
}

QString sinkingController::get_sensor_status()
{

    std::cout<<proc_sinking_model.sinkingProcessHandler->get_sys_obj()->getSubSysStatus("delta")<<std::endl;
    if (proc_sinking_model.sinkingProcessHandler->get_sys_obj()->getSubSysStatus("delta") == true) return "true";
    else return "false";
}