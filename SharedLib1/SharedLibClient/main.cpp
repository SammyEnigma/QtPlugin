#include <QCoreApplication>
#include <qdebug.h>
#include "../SharedLib/SharedLib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //  测试库
    SharedLib lib;
    qDebug() << lib.add(2, 3);
    qDebug() << subtract(5, 2);

    return a.exec();
}
