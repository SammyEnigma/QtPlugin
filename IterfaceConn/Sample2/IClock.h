#ifndef ICLOCK_H
#define ICLOCK_H

#include <qobject.h>

class IClock
{
public:
    ~IClock() {}

    virtual void doSomething() = 0;
    virtual bool connectToAlarm(QObject* recevier, const char* pszSlot, bool isConnect) const = 0;
};

#endif // ICLOCK_H
