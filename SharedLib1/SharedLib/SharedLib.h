#ifndef SHAREDLIB_H
#define SHAREDLIB_H

#include "sharedlib_global.h"

SHAREDLIBSHARED_EXPORT int subtract(int x, int y);

class SHAREDLIBSHARED_EXPORT SharedLib
{

public:
    SharedLib();
    int add(int x, int y);
};

#endif // SHAREDLIB_H
