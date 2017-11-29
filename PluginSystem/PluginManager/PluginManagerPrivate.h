#ifndef PLUGINMANAGERPRIVATE_H
#define PLUGINMANAGERPRIVATE_H

#include <qobject.h>
#include <QtCore>

class PluginManagerPrivate
{
public:
    PluginManagerPrivate();
    ~PluginManagerPrivate();

    bool check(const QString& path);

public:
    QHash<QString, QVariant> m_names;   //  插件路径 - 名称
    QHash<QString, QVariant> m_versions;    //  插件路径 - 版本
    QHash<QString, QVariantList> m_dependencies;    //  插件路径 - 其额外依赖的插件
    QHash<QString, QPluginLoader*> m_loaders;   //  插件路径 - QPluginLoader 实例
};

#endif // PLUGINMANAGERPRIVATE_H
