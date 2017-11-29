#include "PluginManager.h"
#include <qcoreapplication.h>
#include <QtCore>

#include "PluginManagerPrivate.h"
#include "../Plugin/Plugin.h"

PluginManager* PluginManager::m_instance = nullptr;

PluginManager::PluginManager()
{

}

PluginManager::~PluginManager()
{

}

PluginManager *PluginManager::instance()
{
    if(m_instance == nullptr)
        m_instance = new PluginManager;

    return m_instance;
}

void PluginManager::loadAll()
{
    //  进入插件目录
    QDir path = QDir(qApp->applicationDirPath());
    path.cd("plugins");

    //  初始化插件中的元数据
    foreach (QFileInfo info, path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot))
    {
        scan(info.absoluteFilePath());
    }

    //  加载插件
    foreach (QFileInfo info, path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot))
    {
        load(info.absoluteFilePath());
    }
}

void PluginManager::scan(const QString &path)
{
    /*****
         *  判断是否是库（后缀有效性）
         * Windows：.dll、.DLL
         * Unix/Linux：.so
       *****/
    if(!QLibrary::isLibrary(path))
        return;

    //  获取元数据（名称、版本、依赖库)
    QPluginLoader* loader = new QPluginLoader(path);
    QJsonObject jsonObject = loader->metaData().value("MetaData").toObject();

    d->m_names.insert(path, jsonObject.value("name").toVariant());
    d->m_versions.insert(path, jsonObject.value("version").toVariant());
    d->m_dependencies.insert(path, jsonObject.value("dependencies").toArray().toVariantList());

    delete loader;
    loader = nullptr;
}

void PluginManager::load(const QString &path)
{
    //  判断是否是库
    if(!QLibrary::isLibrary(path))
        return;

    //  检测插件依赖
    if(!d->check(path))
        return;

    //  加载插件
    QPluginLoader* loader = new QPluginLoader(path);
    if(loader->load())
    {
        //  如果继承自 Plugin， 则认为是自己的插件（防止外部插件注入）
        Plugin* plugin = qobject_cast<Plugin*>(loader->instance());
        if(plugin)
        {
            d->m_loaders.insert(path, loader);
        }
        else
        {
            delete loader;
            loader = nullptr;
        }
    }
}

void PluginManager::unloadAll()
{
    foreach (const QString& path, d->m_loaders.keys())
    {
        unload(path);
    }
}

void PluginManager::unload(const QString &path)
{
    QPluginLoader* loader = d->m_loaders.value(path);

    //  卸载插件，并从内部数据结构中移除
    if(loader->unload())
    {
        d->m_loaders.remove(path);
        delete loader;
        loader = nullptr;
    }
}

QList<QPluginLoader *> PluginManager::plugins()
{
    return d->m_loaders.values();
}
