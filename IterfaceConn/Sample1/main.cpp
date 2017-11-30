#include <QCoreApplication>

#include "DigitalClock.h"
#include "Monitor.h"

//  将"信号"定义为一个纯虚函数

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DigitalClock clock;
    Monitor monitor;
    monitor.monitorAlarm(&clock);
    emit clock.alarm();

    return a.exec();
}
