TEMPLATE = app
TARGET = tictactoe
 
QT = core gui
 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += \
    ./include \
    ./gen/include \

FORMS += \
    forms/board.ui \

SOURCES += \
    main.cpp \
    src/views/QtBoardView.cpp \

HEADERS += \
    include/QtBoardView.h \

DESTDIR = gen/out
OBJECTS_DIR = obj
UI_DIR = gen/include
