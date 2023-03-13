#include "mainController.h"

/***************** main controller *******************/

mainController::mainController()
{
    std::cout << "main controller constructed" << "\n";
}

mainController::~mainController()
{
    std::cout << "main controller desctructed" << "\n";
}

void mainController::on_execute_process_clicked()
{
    emit resetProgressBar();

    modelManager.processManager->start_process();
    time_elapsed = modelManager.processManager->get_elapsed_time();

    emit finishedProc();
}

void mainController::on_execute_all_clicked()
{
    auto callback = std::bind(&mainController::getProgressUpdate, this, std::placeholders::_1);
    modelManager.processManager->start_all(callback);
    time_elapsed = modelManager.processManager->get_elapsed_time();

    emit finishedAll();
}
void mainController::on_abort_all_clicked()
{
    modelManager.processManager->stop_all();
    time_elapsed = modelManager.processManager->get_elapsed_time();

    emit finishedAll();
}
void mainController::getProgressUpdate(int proc_id) // x porc from proc list
{
    // emit proc id
    emit valueChanged(proc_id);
}

void mainController::updateLcdTime(QLCDNumber* Lcd)
{
    Lcd->display(time_elapsed);
    time_elapsed = 0;
}
void mainController::updateProgressBar(QProgressBar* ProgBar, int value)
{
    ProgBar->setValue(value);
}

void mainController::execute_process(std::string name)
{
    modelManager.processManager->start_process(name);
    time_elapsed = modelManager.processManager->get_elapsed_time();

    emit finishedProc();

}
void mainController::execute_process(int id)
{
        emit resetProgressBar();

    modelManager.processManager->start_process(id);
    time_elapsed = modelManager.processManager->get_elapsed_time();

    emit finishedProc();

}
void mainController::abort_current_process(int id)
{
        emit resetProgressBar();

    modelManager.processManager->stop_process(id);
    time_elapsed = modelManager.processManager->get_elapsed_time();

    emit finishedProc();

}
void mainController::setProgressUpdate(int prog)
{
    progress =   prog;
}
