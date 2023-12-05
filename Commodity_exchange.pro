QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buy_prod.cpp \
    buy_prod_factory.cpp \
    buyers.cpp \
    buyers_factory.cpp \
    buyers_form.cpp \
    estate.cpp \
    facade_method.cpp \
    factory.cpp \
    factory_help.cpp \
    history.cpp \
    htable.cpp \
    main.cpp \
    mainwindow.cpp \
    sellers.cpp \
    sellers_factory.cpp \
    sellers_form.cpp

HEADERS += \
    buy_prod.h \
    buy_prod_factory.h \
    buyers.h \
    buyers_factory.h \
    buyers_form.h \
    estate.h \
    facade_method.h \
    factory.h \
    factory_help.h \
    history.h \
    htable.h \
    mainwindow.h \
    sellers.h \
    sellers_factory.h \
    sellers_form.h

FORMS += \
    buyers_form.ui \
    history.ui \
    mainwindow.ui \
    sellers_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
