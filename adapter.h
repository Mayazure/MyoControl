#ifndef ADAPTER_H
#define ADAPTER_H

#include <QThread>
#include <QString>

#include "myo/myo.hpp"
#include "datacollector.h"

class DataCollector;

class Adapter : public QThread
{
    Q_OBJECT

public:
    explicit Adapter(QObject *parent = 0);

    volatile void setRunningFlag(bool flag);
    volatile void setLoggingFlag(bool flag);
    void setEvent(QString event);

    void updateConsole(QString data);
    void updateTotalNum(int label);

    void setPath(QString filePath, QString fileName);
    QString getFilePath();
    QString getFileName();

protected:
    void run();

private:
    volatile bool threadRun = false;
    QString filePath;
    QString fileName;
    int emgNum = 0;
    int gyrNum = 0;
    int accNum = 0;
    int oriNum = 0;
    int oreNum = 0;
    DataCollector *dc;

signals:
    void requestUpdateConsole(QString data);
    void requestUpdateTotalNum(QString num, int label);

};

#endif // ADAPTER_H
