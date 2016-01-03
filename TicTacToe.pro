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
    src/views/QtLabelClickable.cpp \
    src/helpers/BoardActionsHelper.cpp \
    src/helpers/Utils.cpp \
    $$files(gen/src/*.cpp) \

HEADERS += \
    include/QtBoardView.h \
    include/BoardActionsHelper.h \
    include/QtLabelClickable.h \
    include/Utils.h \

DESTDIR = gen/out
OBJECTS_DIR = obj
UI_DIR = gen/include
MOC_DIR = gen/src
