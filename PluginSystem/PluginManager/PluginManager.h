#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "pluginmanager_global.h"
#include <qobject.h>

class QPluginLoader;
class PluginManagerPrivate;

class PLUGINMANAGERSHARED_EXPORT PluginManager : public QObject
{
    Q_OBJECT

public:
    static PluginManager* instance();

    //  加载所有插件
    void loadAll();

    //  扫描 JSON 文件中的元数据
    void scan(const QString& path);

    //  加载插件
    void load(const QString& path);

    //  卸载所有插件
    void unloadAll();

    //  卸载插件
    void unload(const QString& path);

    //  获取所有插件
    QList<QPluginLoader*> plugins();

private:
    PluginManager();
    ~PluginManager();

private:
    static PluginManager* m_instance;
    PluginManagerPrivate* d;
};

#endif // PLUGINMANAGER_H
