#include "programmer.h"
#include <QtDebug>


QString Programmer::name()
{
    return "Pony";
}

void Programmer::eat()
{
    qDebug() << "Pizza";
}

void Programmer::sleep()
{
    qDebug() << "8 hours";
}

void Programmer::doSomething()
{
    qDebug() << "Coding...";
}
