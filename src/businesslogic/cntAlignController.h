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
#include "cntAlignModel.h"
class cntAlignController : public QObject
{
    Q_OBJECT
public:
    cntAlignController(/* args */);
    ~cntAlignController();
signals:

public slots:
    // view distance sensors
private:
    cntAlignModel cntModel;

};