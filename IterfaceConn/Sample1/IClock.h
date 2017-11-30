#ifndef ICLOCK_H
#define ICLOCK_H

class IClock
{
public:
    ~IClock() {}
    virtual void doSomething() = 0;

    //  不是一个信号（但可以当做信号来用），因为IClock不是QObject
    virtual void alarm() = 0;
};

#endif // ICLOCK_H
