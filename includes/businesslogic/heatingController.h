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
#include "heatingModel.h"
class heatingController : public QObject
{
    Q_OBJECT
public:
    heatingController(/* args */);
    ~heatingController();
signals:

public slots:
    // view distance sensors
private:
    heatingModel heatModel;

};