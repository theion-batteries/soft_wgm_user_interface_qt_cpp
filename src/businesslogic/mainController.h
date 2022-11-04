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
#include "mainModel.h"
class mainController : public QObject
{
    //Q_OBJECT
public:
    mainController(/* args */);
    ~mainController();
signals:

public slots:
    // view distance sensors
private:
    mainModel modelManager;

};