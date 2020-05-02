QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    jnilistener.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    about.h \
    jniexport.h \
    jnilistener.h \
    mainwindow.h

FORMS += \
    about.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Java.java

unix:!macx: LIBS += -L/usr/lib/jvm/java-11-openjdk-amd64/jre/lib/amd64/
INCLUDEPATH += /usr/lib/jvm/java-11-openjdk-amd64/include/linux
INCLUDEPATH +=/usr/lib/jvm/java-11-openjdk-amd64/include
DEPENDPATH += /usr/lib/jvm/java-11openjdk-amd64/include

unix:!macx: LIBS += -L/usr/lib/jvm/java-11-openjdk-amd64/jre/lib/amd64/server/
INCLUDEPATH += /usr/lib/jvm/java-11-openjdk-amd64/jre/lib/amd64/server
DEPENDPATH += /usr/lib/jvm/java-11-openjdk-amd64/jre/lib/amd64/server

RESOURCES += \
    resources.qrc
