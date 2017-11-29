#include "PluginManagerPrivate.h"
//#include <qhash.h>
//#include <QtCore>

PluginManagerPrivate::PluginManagerPrivate()
{

}

PluginManagerPrivate::~PluginManagerPrivate()
{

}

bool PluginManagerPrivate::check(const QString &path)
{
    foreach (QVariant item, m_dependencies.value(path))
    {
        QVariantMap map = item.toMap();
        //  依赖的插件名称、版本、路径
        QVariant name = map.value("name");
        QVariant version = map.value("version");
        QString path = m_names.key(name);

        /*************************** 检测插件是否依赖于其他插件 ***************************/
        //  先检测插件名称
        if(!m_names.values().contains(name))
        {
            qDebug() << Q_FUNC_INFO << " Missing dependency: " << name.toString() << " for plugin " << path;
            return false;
        }

        //  再检测插件版本
        if(m_versions.value(path) != version)
        {
            qDebug() << Q_FUNC_INFO << " Version Mismatch: "
                     << name.toString() << " version " << m_versions.value(path).toString() << " but "
                     << version.toString() << " required for plugin " << path;
            return false;
        }

        //  然后，检测被依赖的插件是否还依赖于另外的插件
        if(!check(path))
        {
            qDebug() << Q_FUNC_INFO << " Corrputed dependency: " << name.toString() << " for plugin " << path;
            return false;
        }
    }

    return true;
}
