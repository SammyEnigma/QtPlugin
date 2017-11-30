#include "Monitor.h"

#include <qdebug.h>

void Monitor::monitorAlarm(IClock *clock)
{
    QObject* clockObject = dynamic_cast<QObject*>(clock);
    if(clockObject)
    {
        connect(clockObject, SIGNAL(alarm()), this, SLOT(onAlarm()));
    }
    else
    {
        qWarning() << "Cannot monitor Alarm.";
    }
}

void Monitor::onAlarm()
{
    qDebug() << "Get up.";
}
