#include "coolingController.h"

/***************** cooling controller *******************/

coolingController::coolingController()
{
    std::cout << "cooling controller constructed" << std::endl;
}

coolingController::~coolingController()
{
    std::cout << "cooling controller desctructed" << std::endl;
}


void coolingController::on_connect_motion_axis_ph_clicked()
{
    coolModel.coolingProcessHandler->get_sys_ptr()->connect_motion_axis();
    emit axisConnected();
}

void coolingController::on_connect_rotation_axis_ph_clicked()
{
coolModel.coolingProcessHandler->get_sys_ptr()->connect_rotation_axis();
    emit rotationConnected();
}
void coolingController::on_connect_ph_clicked()
{
coolModel.coolingProcessHandler->get_sys_ptr()->connect_ph();
    emit phConnected();
}


void coolingController::on_run_cooling_process_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_ph_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    coolModel.coolingProcessHandler->start_process();
    time_elapsed = coolModel.coolingProcessHandler->get_elapsed_time();
}

void coolingController::on_stop_cooling_process_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_ph_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    coolModel.coolingProcessHandler->stop_process();
    time_elapsed = coolModel.coolingProcessHandler->get_elapsed_time();
}
void coolingController::on_ph_move_center_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_ph_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    auto def = coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController();
    def->ph_rotate_to_center(def->get_rotate_to_center_param());
    def->ph_motion_move_to_center(def->get_center_target_distance());
}
void coolingController::on_linear_move_home_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_ph_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_axis_ptr()->move_home();
}
void coolingController::on_rotation_move_home_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_ph_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_rotary_axis_ptr()->move_home();
}
void coolingController::on_ph_print_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_ph_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_ph_ptr()->startPrinting();
}






void coolingController::updateLcdTime(QLCDNumber* Lcd)
{
    Lcd->display(time_elapsed);
    time_elapsed = 0;
}

void coolingController::updateLcdAxisPosition(QLCDNumber* Lcd)
{
    while (get_axis_status()) // while connected, launch thread display
    {
        std::cout << "updating lcd distance " << std::endl;
        Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_axis_position());
        std::cout << "lcd distance thread id: " << QThread::currentThreadId() << std::endl;
        QThread::currentThread()->sleep(10);
    }

}
void coolingController::updateLcdRotationPosition(QLCDNumber* Lcd)
{
    while (get_rotary_status())
    {
        std::cout << "updating lcd position " << std::endl;
        Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_rotary_axis_ptr()->get_position());
        std::cout << "lcd position thread id: " << QThread::currentThreadId() << std::endl;
        QThread::currentThread()->sleep(10);
    }
}
// TODO :
void coolingController::updateLcdPhFrequency(QLCDNumber* Lcd)
{
    while (get_ph_status())
    {
        std::cout << "updating lcd position " << std::endl;
        Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_rotary_axis_ptr()->get_position());
        std::cout << "lcd position thread id: " << QThread::currentThreadId() << std::endl;
        QThread::currentThread()->sleep(10);
    }
}




bool coolingController::get_axis_status()
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysStatus("axis_motion");
}

bool coolingController::get_rotary_status()
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysStatus("distance_sensor");
}

bool coolingController::get_ph_status()
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysStatus("distance_sensor");
}
std::string coolingController::sendAxisCmd(std::string Cmd)
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->sendDirectCmdAxis(Cmd);
}

void coolingController::reload_ph_config_file()
{
    std::cout << "file closed succefuly, updating parameters" << std::endl;
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->reload_config_file();
}

bool coolingController::getProcessStatus()
{
    std::cout << "getting process status" << std::endl;
    return coolModel.coolingProcessHandler->is_proc_success();
}

// label update
void coolingController::updateLabelAxis(QLabel* label)
{
    if (get_axis_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void coolingController::updateLabelRotation(QLabel* label)
{
    if (get_axis_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}

void coolingController::updateLabelPh(QLabel* label)
{
    if (get_ph_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void coolingController::updateLabelProcess(QLabel* label)
{
    if (getProcessStatus())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void coolingController::updateLabelAxisResponse(QLabel* label, QString cmd)
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
void coolingController::updateLabelPhResponse(QLabel* label, QString cmd)
{
    if (!get_ph_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    label->clear();
    std::cout << "user cmd: " << cmd.toStdString() << std::endl;
    auto strCmd = cmd.toStdString();
    std::string resp = sendAxisCmd(strCmd);
    emit phReplied(resp);
}
void coolingController::updateLabelRotResponse(QLabel* label, QString cmd)
{
    if (!get_rotary_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    label->clear();
    std::cout << "user cmd: " << cmd.toStdString() << std::endl;
    auto strCmd = cmd.toStdString();
    std::string resp = sendAxisCmd(strCmd);
    emit rotaryReplied(resp);
}