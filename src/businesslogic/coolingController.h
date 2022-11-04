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
#include "coolingModel.h"
class coolingController : public QObject
{
   // Q_OBJECT
public:
    coolingController(/* args */);
    ~coolingController();
signals:

public slots:
    // view distance sensors
private:
    coolingModel coolModel;

};