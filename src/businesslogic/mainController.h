#pragma once 
// qt
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QLCDNumber>
#include <QFile>
#include <QProcess>
#include <QLabel>
#include <QString>
#include <QProgressBar>
#include <QListWidget>
#include <QListWidgetItem>
#include <QtConcurrent>

// mvc
#include <atomic>
#include "mainModel.h"
class mainController: public QObject
{
    Q_OBJECT
public:
    mainController(/* args */);
    ~mainController();
signals:
    void pressed();
    void triggered();
    void returnPressed(); // line edit enter key pressed
    void valueChanged();
    void finishedProc();
    void finishedAll();
    void selected();
public slots:
    void on_execute_process_clicked();
    void on_execute_all_clicked();

    void execute_process(std::string name);
    void execute_process(int id);
    void updateLcdTime(QLCDNumber* Lcd);
    void updateProgressBar(QProgressBar* ProgBar);

private:
    mainModel modelManager;
    double time_elapsed;

};