#include "extractingController.h"

/***************** extracting controller *******************/

extractingController::extractingController()
{
    std::cout << "extracting controller constructed" << "\n";
    extractModel = new extractingModel( new wgm_processes::sinking_process() );
}

extractingController::~extractingController()
{
    std::cout << "extracting controller desctructed" << "\n";
    delete extractModel;
}


void extractingController::on_extract_connect_distance_sensor_clicked()
{
    extractModel->extractingProcessHandler->get_sys_ptr()->connect_sensor();
    emit sensorConnected();
}

void extractingController::on_extract_connect_motion_axis_clicked()
{
extractModel->extractingProcessHandler->get_sys_ptr()->connect_motion_axis();
    emit axisConnected();
}

void extractingController::on_run_extracting_process_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    extractModel->extractingProcessHandler->start_process();
    time_elapsed = extractModel->extractingProcessHandler->get_elapsed_time();
}

void extractingController::on_stop_extracting_process_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    extractModel->extractingProcessHandler->stop_process();
    time_elapsed = extractModel->extractingProcessHandler->get_elapsed_time();
}
void extractingController::on_extract_move_home_clicked()
{
    if (!get_axis_status() || !get_sensor_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    extractModel->extractingProcessHandler->get_sys_ptr()->getSubSysController()->extract_move_home();
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
        std::cout << "updating lcd distance " << "\n";
        Lcd->display(extractModel->extractingProcessHandler->get_sys_ptr()->getSubSysController()->get_sensor_values());
        std::cout << "lcd distance thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }

}
void extractingController::updateLcdPosition(QLCDNumber* Lcd)
{
    while (get_axis_status())
    {
        std::cout << "updating lcd position " << "\n";
        Lcd->display(extractModel->extractingProcessHandler->get_sys_ptr()->getSubSysController()->get_axis_position());
        std::cout << "lcd position thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}
bool extractingController::get_axis_status()
{
    return extractModel->extractingProcessHandler->get_sys_ptr()->getSubSysStatus("axis_motion");
}

bool extractingController::get_sensor_status()
{
    return extractModel->extractingProcessHandler->get_sys_ptr()->getSubSysStatus("distance_sensor");
}

std::string extractingController::sendAxisCmd(std::string Cmd)
{
    return extractModel->extractingProcessHandler->get_sys_ptr()->getSubSysController()->sendDirectCmdAxis(Cmd);
}

void extractingController::reload_whs_config_file()
{
    std::cout << "file closed succefuly, updating parameters" << "\n";
    extractModel->extractingProcessHandler->get_sys_ptr()->getSubSysController()->reload_config_file();
}

bool extractingController::getProcessStatus()
{
    std::cout << "getting process status" << "\n";
    return extractModel->extractingProcessHandler->is_proc_success();
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
        std::cout << "device not connected " << "\n";
        return;
    }
    label->clear();
    std::cout << "user cmd: " << cmd.toStdString() << "\n";
    auto strCmd = cmd.toStdString();
    std::string resp = sendAxisCmd(strCmd);
    emit axisReplied(resp);
}

