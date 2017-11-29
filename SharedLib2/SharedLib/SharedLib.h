#ifndef SHAREDLIB_H
#define SHAREDLIB_H

#include "sharedlib_global.h"

extern "C"
{
    SHAREDLIBSHARED_EXPORT int subtract(int x, int y);
}

class SHAREDLIBSHARED_EXPORT SharedLib
{

public:
    SharedLib();
};

#endif // SHAREDLIB_H
