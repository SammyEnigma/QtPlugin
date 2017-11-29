#ifndef PLUGIN_H
#define PLUGIN_H

#include "plugin_global.h"
#include <qobject.h>

class PLUGINSHARED_EXPORT Plugin : public QObject
{
    Q_OBJECT

public:
    Plugin();
    virtual ~Plugin(){}
};

#define PluginInterface_IID "com.github.wangds.PluginInterface"
Q_DECLARE_INTERFACE(Plugin, PluginInterface_IID)

#endif // PLUGIN_H
