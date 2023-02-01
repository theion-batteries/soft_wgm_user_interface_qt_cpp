#include "mainController.h"

/***************** main controller *******************/

mainController::mainController()
{
    std::cout << "main controller constructed" << std::endl;
}

mainController::~mainController()
{
    std::cout << "main controller desctructed" << std::endl;
}

void mainController::on_execute_process_clicked()
{

    modelManager.processManager->start_process();
    emit finishedProc();
}

void mainController::on_execute_all_clicked()
{
    modelManager.processManager->start_all();
    emit finishedAll();
}

void mainController::updateLcdTime(QLCDNumber* Lcd)
{
    Lcd->display(time_elapsed);
    time_elapsed = 0;
}
void mainController::updateProgressBar(QProgressBar* ProgBar)
{
    ProgBar->setValue(50);
}

void mainController::execute_process(std::string name)
{
    modelManager.processManager->start_process(name);
    time_elapsed = modelManager.processManager->get_elapsed_time();

    emit finishedProc();

}
void mainController::execute_process(int id)
{
    modelManager.processManager->start_process(id);
    time_elapsed = modelManager.processManager->get_elapsed_time();

    emit finishedProc();

}