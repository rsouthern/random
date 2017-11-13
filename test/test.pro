include(../common.pri)
TEMPLATE=app
TARGET=$$BIN_INSTALL_DIR/test

SOURCES += src/*.cpp

INCLUDEPATH += $$INC_INSTALL_DIR

OBJECTS_DIR = obj

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic

LIBS += -L$$LIB_INSTALL_DIR -lrand_cpu -lrand_gpu

QMAKE_RPATHDIR += $$LIB_INSTALL_DIR