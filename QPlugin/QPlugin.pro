TEMPLATE = subdirs

#SUBDIRS += \
#    plugin \
#    app

SUBDIRS += $$PWD/plugin/plugin.pro \
                   $$PWD/app/app.pro

CONFIG += ordered
