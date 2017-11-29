#ifndef PROGRAMMER_H
#define PROGRAMMER_H

//#include "plugin_global.h"
#include <QObject>
#include "person.h"

class Programmer :
        public QObject, IPerson
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID IPerson_iid FILE "programmer.json")   //  该宏包含插件的IID，并指向一个包含插件元数据的Json文件。该Json文件会被编译到插件中，无需安装
    Q_INTERFACES(IPerson)   //  该宏用于告诉Qt该类实现的接口

public:
    virtual QString name() override;
    virtual void eat() override;
    virtual void sleep() override;
    virtual void doSomething() override;
};

#endif // PROGRAMMER_H
