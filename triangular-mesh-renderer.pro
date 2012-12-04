#-------------------------------------------------
#
# Project created by QtCreator 2012-11-28T21:55:10
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = triangular-mesh-renderer
TEMPLATE = app


SOURCES += main.cc\
        c_main_window.cc \
    c_data.cc \
    c_gl_widget.cc \
    c_triangulation.cc

HEADERS  += c_main_window.hh \
    c_gl_widget.hh \
    t_types.hh \
    c_triangulation.hh \
    c_data.hh

FORMS    += c_main_window.ui

unix: LIBS += -lCGAL -lgmp
