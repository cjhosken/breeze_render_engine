# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = breeze_render_engine
DESTDIR = ../x64/Release
CONFIG += release
LIBS += -L"." \
    -lopengl32 \
    -l$(NOINHERIT)
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += release
UI_DIR += .
RCC_DIR += .
win32:RC_FILE = ./breeze_render_engine.rc
QT += core gui widgets openglwidgets opengl;
include(breeze_render_engine.pri)
