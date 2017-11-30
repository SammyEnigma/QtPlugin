#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QObject>
#include <qdebug.h>
#include "IClock.h"

class DigitalClock : public QObject, public IClock
{
    Q_OBJECT

public:
    DigitalClock(){}

    void doSomething()
    {
        qDebug() << "Do something...";
    }

signals:
    //  实现由 moc 来完成
    void alarm() override;


};

#endif // DIGITALCLOCK_H
