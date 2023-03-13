#include "coolingController.h"

/***************** cooling controller *******************/

coolingController::coolingController()
{
    std::cout << "cooling controller constructed" << "\n";
}

coolingController::~coolingController()
{
    std::cout << "cooling controller desctructed" << "\n";
}

void coolingController::on_connect_ph_x_y_motion_clicked()
{
    coolModel.coolingProcessHandler->get_sys_ptr()->connect_xy_motion_axis();
    emit axisConnected();
}

void coolingController::on_connect_ph_trigger_clicked()
{
    coolModel.coolingProcessHandler->get_sys_ptr()->connect_ph_trigger();
    emit rotationConnected();
}
void coolingController::on_connect_ph_meteor_clicked()
{
    coolModel.coolingProcessHandler->get_sys_ptr()->connect_ph();
    emit phConnected();
}

void coolingController::on_run_cooling_process_clicked()
{

    if (!get_axis_status())
    {
        std::cout << " Axis Device is not connected \n";
        return;
    }
    if (!get_rotary_status())
    {
        std::cout << " Rotation Device is not connected \n";
        return;
    }

    if (!get_trigger_status())
    {
        std::cout << "Trigger device not connected \n";
        return;
    }

    coolModel.coolingProcessHandler->start_process();
    time_elapsed = coolModel.coolingProcessHandler->get_elapsed_time();
}

void coolingController::on_stop_cooling_process_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    coolModel.coolingProcessHandler->stop_process();
    time_elapsed = coolModel.coolingProcessHandler->get_elapsed_time();
}

/************************** Algorithms ***********************/
void coolingController::on_ph_move_offset_clicked(const double position)
{
    if (!get_axis_status() || !get_rotary_status() || !get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    auto def = coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController();
    def->ph_motion_move_offset(position);
}


void coolingController::on_ph_rotate_clicked(const double degree)
{
    if (!get_axis_status() || !get_rotary_status() || !get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    auto def = coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController();
    def->ph_rotate_to(degree);
}


void coolingController::on_ph_move_center_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    auto def = coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController();
    def->ph_rotate_to_center(def->get_rotate_to_center_param());
    def->ph_motion_move_to_center(def->get_center_target_distance());
}
void coolingController::on_ph_motion_xy_move_home_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->ph_motion_home_all();
}

void coolingController::on_ph_trigger_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->ph_trigger_print();
}

void coolingController::on_ph_rotate_center_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->ph_rotate_center();
}

void coolingController::on_ph_rotate_print_clicked()
{
    if (!get_axis_status() || !get_rotary_status() || !get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->ph_rotate_and_print();
}

/*********************** Lcd Label ******************/

void coolingController::updateLcdTime(QLCDNumber *Lcd)
{
    Lcd->display(time_elapsed);
    time_elapsed = 0;
}

void coolingController::updateLcdAxisPosition(QLCDNumber *Lcd)
{
    while (get_axis_status()) // while connected, launch thread display
    {
        std::cout << "updating lcd linear position" << "\n";
        Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_axis_position());
        std::cout << "lcd distance thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}
void coolingController::updateLcdRotationPosition(QLCDNumber *Lcd)
{
    while (get_rotary_status())
    {
        std::cout << "updating lcd rotation position " << "\n";
        Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_rotation_position());
        std::cout << "lcd rotation position thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}
void coolingController::updateLcdAxisVelocity(QLCDNumber *Lcd)
{
    while (get_axis_status()) // while connected, launch thread display
    {
        std::cout << "updating lcd x linear velocity " << "\n";
        Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_axis_velocity());
        std::cout << "lcd distance thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}
void coolingController::updateLcdRotationVelocity(QLCDNumber *Lcd)
{
    while (get_rotary_status())
    {
        std::cout << "updating lcd y rotation velocity " << "\n";
        Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_rotation_velocity());
        std::cout << "lcd rotation position thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}
// combined
void coolingController::updateLcdXYPosition(QLCDNumber *LcdX, QLCDNumber *LcdY)
{
    while (get_axis_status())
    {
        auto x_y = coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_xy_position();
        std::cout << "updating lcd x linear position: " << x_y.first << "\n";
        LcdX->display(x_y.first);
        std::cout << "updating lcd y rotation position: " << x_y.second << "\n";
        LcdY->display(x_y.second);
        std::cout << "lcd update positions thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}

void coolingController::updateLcdXYVelocity(QLCDNumber *LcdX, QLCDNumber *LcdY)
{
    while (get_axis_status())
    {
        auto x_y = coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_xy_velocity();

        std::cout << "updating lcd x linear velocity: " << x_y.first << "\n";
        LcdX->display(x_y.first);
        std::cout << "updating lcd y rotation velocity: " << x_y.second << "\n";
        LcdY->display(x_y.second);
        std::cout << "lcd update velocity thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(20);
    }
}
void coolingController::updateLcdXY(QLCDNumber *LcdPosX, QLCDNumber *LcdPosY, QLCDNumber *LcdVelX, QLCDNumber *LcdVelY)
{
    while (get_axis_status())
    {
        auto x_y = coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_xy_position();
        std::cout << "updating lcd x linear position: " << x_y.first << "\n";
        LcdPosX->display(x_y.first);
        std::cout << "updating lcd y rotation position: " << x_y.second << "\n";
        LcdPosY->display(x_y.second);
        std::cout << "lcd update positions thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(5);
        x_y = coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_xy_velocity();
        std::cout << "updating lcd x linear velocity: " << x_y.first << "\n";
        LcdVelX->display(x_y.first);
        std::cout << "updating lcd y rotation velocity: " << x_y.second << "\n";
        LcdVelY->display(x_y.second);
        std::cout << "lcd update velocity thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(5);
    }
}

// PH
void coolingController::updateLcdPhFrequency(QLCDNumber *Lcd)
{
    while (get_trigger_status())
    {
        std::cout << "updating lcd ph frequency " << "\n";
        // Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_rotation_position());
        std::cout << "lcd ph frequency thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}

void coolingController::updateLcdPhDropletVolume(QLCDNumber *Lcd)
{
    while (get_trigger_status())
    {
        std::cout << "updating lcd ph Droplet Volume " << "\n";
        // Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_rotation_position());
        std::cout << "lcd ph Droplet Volume thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}

void coolingController::updateLcdPhLiquidTemperature(QLCDNumber *Lcd)
{
    while (get_trigger_status())
    {
        std::cout << "updating lcd ph Liquid Temperature " << "\n";
        // Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_rotation_position());
        std::cout << "lcd ph Liquid Temperature thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}

void coolingController::updateLcdPhNumberActiveNuzzles(QLCDNumber *Lcd)
{
    while (get_trigger_status())
    {
        std::cout << "updating lcd ph Number Active Nuzzles " << "\n";
        // Lcd->display(coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_xy_axis_ptr()->get_rotation_position());
        std::cout << "lcd ph Number Active Nuzzles thread id: " << QThread::currentThreadId() << "\n";
        QThread::currentThread()->sleep(10);
    }
}

bool coolingController::get_axis_status()
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_linear_mover_status();
}

bool coolingController::get_rotary_status()
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_rotary_mover_status();
}
bool coolingController::get_trigger_status()
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_trigger_status();
}
bool coolingController::get_ph_status()
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->get_ph_status();
}
std::string coolingController::sendAxisCmd(std::string Cmd)
{
    return coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->sendDirectCmdAxis(Cmd);
}

void coolingController::reload_ph_config_file()
{
    std::cout << "file closed succefuly, updating parameters" << "\n";
    coolModel.coolingProcessHandler->get_sys_ptr()->getSubSysController()->reload_config_file();
}

bool coolingController::getProcessStatus()
{
    std::cout << "getting process status" << "\n";
    return coolModel.coolingProcessHandler->is_proc_success();
}

// label update
void coolingController::updateLabelAxis(QLabel *label)
{
    if (get_axis_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void coolingController::updateLabelTrigger(QLabel *label)
{
    if (get_trigger_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}

void coolingController::updateLabelPh(QLabel *label)
{
    if (get_trigger_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void coolingController::updateLabelProcess(QLabel *label)
{
    if (getProcessStatus())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
void coolingController::updateLabelAxisResponse(QLabel *label, QString cmd)
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
void coolingController::updateLabelPhResponse(QLabel *label, QString cmd)
{
    if (!get_trigger_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    label->clear();
    std::cout << "user cmd: " << cmd.toStdString() << "\n";
    auto strCmd = cmd.toStdString();
    std::string resp = sendAxisCmd(strCmd);
    emit phReplied(resp);
}
void coolingController::updateLabelTrigResponse(QLabel *label, QString cmd)
{
    if (!get_rotary_status())
    {
        std::cout << "device not connected " << "\n";
        return;
    }
    label->clear();
    std::cout << "user cmd: " << cmd.toStdString() << "\n";
    auto strCmd = cmd.toStdString();
    std::string resp = sendAxisCmd(strCmd);
    emit rotaryReplied(resp);
}