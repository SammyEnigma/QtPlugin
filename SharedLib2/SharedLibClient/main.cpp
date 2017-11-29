#include <QCoreApplication>
#include <qdebug.h>
#include <qlibrary.h>
#include "../SharedLib/SharedLib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //  SharedLib.dll与可执行程序位于同一目录
    QLibrary lib("SharedLib");
    if(lib.load())
    {
        typedef int (*Fun)(int, int);
        //  解析符号
        Fun sub = (Fun)(lib.resolve("subtract"));
        if(sub)
        {
            qDebug() << sub(5, 2);
        }
        else
        {
            qDebug() << "Can't resolve subtract";
        }

        //  卸载
        lib.unload();
    }
    else
    {
        qDebug() << lib.errorString();
    }

    return a.exec();
}
