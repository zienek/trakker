# -------------------------------------------------
# Project created by QtCreator 2009-10-23T12:27:39
# -------------------------------------------------
QT += network
TARGET = trakker
TEMPLATE = app
SOURCES += main.cpp \
    trakkercontroller.cpp \
    src/trakkermodel.cpp \
    src/trakker.cpp
HEADERS += trakkercontroller.h \
    src/trakkermodel.h \
    src/trakker.h \
    src/windows_512.h \
    forms/centralwidget.h
FORMS += centralwidget.ui
LIBS += -lfftw3 \
    -lm
RESOURCES += src/application.qrc
