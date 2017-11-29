#include <QCoreApplication>
#include <QPluginLoader>
#include <QDir>
#include <QtDebug>
#include <QJsonObject>
#include <QJsonArray>

#include "plugin/person.h"

static void loadPlugin();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    loadPlugin();

    return a.exec();
}

static void loadPlugin()
{
    //  enter plugin dir
    QDir pluginDir(qApp->applicationDirPath());
    pluginDir.cd("plugins");
    //  查找目录中的所有插件
    QStringList filters;
    filters << "*.dll";
    pluginDir.setNameFilters(filters);
    foreach (QString fileName, pluginDir.entryList())
    {
        QPluginLoader loader(pluginDir.absoluteFilePath(fileName));
        //  返回插件的根组件对象
        QObject* pPlugin = loader.instance();
        if(pPlugin != nullptr)
        {
            //  获取元数据（名称、版本、依赖）
            QJsonObject json = loader.metaData().value("MetaData").toObject();
            qDebug() << "********** MetaData **********";
            qDebug() << json.value("author").toVariant();
            qDebug() << json.value("date").toVariant();
            qDebug() << json.value("name").toVariant();
            qDebug() << json.value("verson").toVariant();
            qDebug() << json.value("depenencies").toVariant();

            //  访问感兴趣的接口
            IPerson* pPerson = qobject_cast<IPerson*>(pPlugin);
            if(pPerson != nullptr)
            {
                qDebug() << "********** IPerson **********";
                qDebug() << pPerson->name();
                pPerson->eat();
                pPerson->sleep();
                pPerson->doSomething();
            }
            else
            {
                qWarning() << "qobject_cast failed";
            }
        }
    }
}
