#include "DigitalClock.h"

#include <qdebug.h>

DigitalClock::DigitalClock()
{

}

void DigitalClock::doSomething()
{
    qDebug() << "Do something...";
}

bool DigitalClock::connectToAlarm(QObject *recevier, const char *pszSlot, bool isConnect) const
{
    if(isConnect)
    {
        return connect(this, SIGNAL(alarm()), recevier, pszSlot);
    }
    else
        return disconnect(this, SIGNAL(alarm()), recevier, pszSlot);
}
