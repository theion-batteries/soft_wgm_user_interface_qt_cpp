#include "heatingController.h"

/***************** heating controller *******************/

heatingController::heatingController()
{
    std::cout << "heating controller constructed" << std::endl;
}

heatingController::~heatingController()
{
    std::cout << "heating controller desctructed" << std::endl;
}

void heatingController::on_connect_heating_dev_clicked()
{
    heatModel.heatingProcessHandler->get_sys_ptr()->getSubSysController().heating_controller_connect();
    emit heaterConnected();

}
void heatingController::on_run_heating_process_clicked()
{
    if (!get_heating_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    heatModel.heatingProcessHandler->start_process();
    time_elapsed = heatModel.heatingProcessHandler->get_elapsed_time();

}
void heatingController::on_stop_heating_proc_clicked()
{
    if (!get_heating_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    heatModel.heatingProcessHandler->stop_process();
    time_elapsed = heatModel.heatingProcessHandler->get_elapsed_time();

}
void heatingController::on_start_heating_clicked()
{

    if (!get_heating_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    auto heaterDef = heatModel.heatingProcessHandler->get_sys_ptr();
    heaterDef->turn_on_heating();
}
void heatingController::on_stop_heating_clicked()
{
    if (!get_heating_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    auto heaterDef = heatModel.heatingProcessHandler->get_sys_ptr();
    heaterDef->turn_off_heating();
}
bool heatingController::get_heating_status()
{
    return heatModel.heatingProcessHandler->get_sys_ptr()->getSubSysStatus("controller");
}
bool heatingController::getProcessStatus()
{
    std::cout << "getting process status" << std::endl;
    return heatModel.heatingProcessHandler->is_proc_success();
}
std::string heatingController::sendDirectCmd(std::string Cmd)
{
    return heatModel.heatingProcessHandler->get_sys_ptr()->getSubSysController().sendDirectCmd(Cmd);
}
void heatingController::reload_heating_config_file()
{
    std::cout << "file closed succefuly, updating parameters" << std::endl;
    heatModel.heatingProcessHandler->get_sys_ptr()->getSubSysController().reload_config_file();
}
// update simple
// lcd update
void heatingController::updateLcdTime(QLCDNumber* Lcd)
{
    Lcd->display(time_elapsed);
    time_elapsed = 0;

}
void heatingController::updateLcdTemperature(QLCDNumber* Lcd)
{
    while (get_heating_status())
    {
        std::cout << "updating lcd temperature " << std::endl;
        Lcd->display(heatModel.heatingProcessHandler->get_sys_ptr()->getSubSysController().get_heating_sulfur_temperature());
        std::cout << "lcd temperature thread id: " << QThread::currentThreadId() << std::endl;
        QThread::currentThread()->sleep(1000);
    }
}
// label update
void heatingController::updateLabelHeater(QLabel* label)
{

    if (get_heating_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
    }

}
void heatingController::updateLabelProcess(QLabel* label)
{
    if (getProcessStatus())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }
}
// response update
void heatingController::updateLabelHeaterResponse(QLabel* label, QString cmd)
{
    if (!get_heating_status())
    {
        std::cout << "device not connected " << std::endl;
        return;
    }
    label->clear();
    std::cout << "user cmd: " << cmd.toStdString() << std::endl;
    auto strCmd = cmd.toStdString();
    std::string resp = sendDirectCmd(strCmd);
    emit heaterReplied(resp);

}

