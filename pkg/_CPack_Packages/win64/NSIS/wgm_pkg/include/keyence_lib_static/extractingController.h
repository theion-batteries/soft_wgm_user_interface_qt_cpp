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
// mvc
#include <atomic>
#include "extractingModel.h"
class extractingController : public QObject
{
    //Q_OBJECT
public:
    extractingController(/* args */);
    ~extractingController();
signals:

public slots:
    // view distance sensors
private:
    extractingModel* extractModel;

};