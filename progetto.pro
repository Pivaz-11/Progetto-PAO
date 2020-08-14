QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    calcolastipendi.cpp \
    home.cpp \
    inseriscivendita.cpp \
    main.cpp \
    mostravendite.cpp \
    pagehandler.cpp \
    autoibrida.cpp \
    azienda.cpp \
    mezzo.cpp \
    mezzocombustione.cpp \
    mezzoelettrico.cpp \
    monopattino.cpp \
    auto.cpp \
    moto.cpp \
    dipendente.cpp

HEADERS += \
    calcolastipendi.h \
    home.h \
    inseriscivendita.h \
    mostravendite.h \
    pagehandler.h \
    autoibrida.h \
    lista.h \
    mezzo.h \
    mezzocombustione.h \
    mezzoelettrico.h \
    monopattino.h \
    auto.h \
    azienda.h \
    dipendente.h \
    moto.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
