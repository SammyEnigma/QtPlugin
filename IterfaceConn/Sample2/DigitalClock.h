#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include "IClock.h"

class DigitalClock : public QObject, public IClock
{
    Q_OBJECT

public:
    DigitalClock();

public:
    void doSomething() override;
    bool connectToAlarm(QObject *recevier, const char *pszSlot, bool isConnect) const override;

signals:
    void alarm();
};

#endif // DIGITALCLOCK_H
