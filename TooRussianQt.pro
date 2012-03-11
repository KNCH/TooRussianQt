#-------------------------------------------------
#
# Project created by QtCreator 2011-12-01T14:06:46
#
#-------------------------------------------------

QT         += core \
              gui \
              sql

DESTDIR     = bin
TARGET      = TooRussianQt
TEMPLATE    = app

OBJECTS_DIR = build/os
UI_DIR      = build/uis
MOC_DIR     = build/mocs

SOURCES    += src/main.cpp \
              src/mainwindow.cpp \
              src/decode.cpp

HEADERS    += src/mainwindow.h \
              src/decode.h

FORMS      += src/forms/mainwindow.ui

RESOURCES  += src/qrc/resources.qrc
