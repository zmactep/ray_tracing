TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pointlight.cpp \
    plane.cpp \
    material.cpp \
    light.cpp \
    color.cpp \
    camera.cpp \
    vector.cpp \
    sphere.cpp \
    shape.cpp \
    setmaterial.cpp \
    scene.cpp \
    rtimage.cpp \
    ray.cpp

HEADERS += \
    ray_tracing.h \
    pointlight.h \
    plane.h \
    material.h \
    light.h \
    color.h \
    camera.h \
    vector.h \
    sphere.h \
    shape.h \
    setmaterial.h \
    scene.h \
    rtimage.h \
    ray.h

QMAKE_CXXFLAGS += -o parallel -Wall

LIBS += -lirc -lIlmImf -lIL -lILU -lpthread
