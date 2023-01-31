#include "extractingController.h"

/***************** extracting controller *******************/

extractingController::extractingController()
{
    std::cout << "extracting controller constructed" << std::endl;
}

extractingController::~extractingController()
{
    std::cout << "extracting controller desctructed" << std::endl;
}


void extractingController::on_sink_connect_distance_sensor_clicked()
{
    extractModel.extractingProcessHandler->get_sys_ptr()->connect_sensor();
    emit sensorConnected();
}

void extractingController::on_sink_connect_motion_axis_clicked()
{
extractModel.extractingProcessHandler->get_sys_ptr()->connect_motion_axis();
    emit axisConnected();
}

void extractingController::on_run_sinking_process_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    extractModel.extractingProcessHandler->start_process();
    time_elapsed = extractModel.extractingProcessHandler->get_elapsed_time();
}

void extractingController::on_stop_sinking_process_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    extractModel.extractingProcessHandler->stop_process();
    time_elapsed = extractModel.extractingProcessHandler->get_elapsed_time();
}
void extractingController::on_move_down_until_sensor_data_valid_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysController()->move_down_until_data_availble();
}
void extractingController::on_move_down_to_surface_contact_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysController()->move_down_to_surface();
}
void extractingController::on_deep_wafer_holder_desired_thickness_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysController()->deep_wafer_holder_desired_thickness();
}
void extractingController::on_monitor_and_calibrate_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysController()->monitor_and_calibrate();
}
void extractingController::updateLcdTime(QLCDNumber* Lcd)
{
    Lcd->display(time_elapsed);
    time_elapsed = 0;
}

void extractingController::updateLcdDistance(QLCDNumber* Lcd)
{
    while (get_sensor_status()) // while connected, launch thread display
    {
        std::cout << "updating lcd distance " << std::endl;
        Lcd->display(extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysController()->get_sensor_values());
        std::cout << "lcd distance thread id: " << QThread::currentThreadId() << std::endl;
        QThread::currentThread()->sleep(10);
    }

}
void extractingController::updateLcdPosition(QLCDNumber* Lcd)
{
    while (get_axis_status())
    {
        std::cout << "updating lcd position " << std::endl;
        Lcd->display(extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysController()->get_axis_position());
        std::cout << "lcd position thread id: " << QThread::currentThreadId() << std::endl;
        QThread::currentThread()->sleep(10);
    }
}
bool extractingController::get_axis_status()
{
    return extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysStatus("axis_motion");
}

bool extractingController::get_sensor_status()
{
    return extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysStatus("distance_sensor");
}

std::string extractingController::sendAxisCmd(std::string Cmd)
{
    return extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysController()->sendDirectCmdAxis(Cmd);
}

void extractingController::reload_whs_config_file()
{
    std::cout << "file closed succefuly, updating parameters" << std::endl;
    extractModel.extractingProcessHandler->get_sys_ptr()->getSubSysController()->reload_config_file();
}

bool extractingController::getProcessStatus()
{
    std::cout << "getting process status" << std::endl;
    return extractModel.extractingProcessHandler->is_proc_success();
}

// label update
void extractingController::updateLabelAxis(QLabel* label)
{
    if (get_axis_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void extractingController::updateLabelSensor(QLabel* label)
{
    if (get_sensor_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void extractingController::updateLabelProcess(QLabel* label)
{
    if (getProcessStatus())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void extractingController::updateLabelAxisResponse(QLabel* label, QString cmd)
{
    if (!get_axis_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    label->clear();
    std::cout << "user cmd: " << cmd.toStdString() << std::endl;
    auto strCmd = cmd.toStdString();
    std::string resp = sendAxisCmd(strCmd);
    emit axisReplied(resp);
}

