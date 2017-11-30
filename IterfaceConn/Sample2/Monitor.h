#ifndef MONITOR_H
#define MONITOR_H

#include <QObject>

#include "IClock.h"

class Monitor : public QObject
{
    Q_OBJECT
public:
    void monitorAlarm(IClock* clock);

signals:

private slots:
    void onAlarm();
};

#endif // MONITOR_H
