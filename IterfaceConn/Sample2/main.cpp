#include <QCoreApplication>

#include "DigitalClock.h"
#include "Monitor.h"

//  在接口中定义信号槽的连接方式

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DigitalClock clock;
    Monitor monitor;
    monitor.monitorAlarm(&clock);
    emit clock.alarm();

    return a.exec();
}
