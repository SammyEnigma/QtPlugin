#include "Monitor.h"

#include <qdebug.h>

void Monitor::monitorAlarm(IClock *clock)
{
    bool isConnect = clock->connectToAlarm(this, SLOT(onAlarm()), true);
    if(isConnect)
    {
        qWarning() << "Signal has connected.";
    }
    else
        qWarning() << "Signal connect failed.";
}

void Monitor::onAlarm()
{
    qDebug() << "Get up.";
}
