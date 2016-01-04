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
    src/components/Board.cpp \
    src/components/Cell.cpp \
    src/components/Player.cpp \
    src/helpers/BoardActionsHelper.cpp \
    src/helpers/Utils.cpp \
    src/strategies/NaiveStrategy.cpp \
    src/views/QtBoardView.cpp \
    src/views/QtLabelClickable.cpp \
    src/Game.cpp \
    $$files(gen/src/*.cpp) \

HEADERS += \
    include/Board.h \
    include/BoardActionsHelper.h \
    include/Cell.h \
    include/CommonIncludes.h \
    include/Game.h \
    include/IStrategy.h \
    include/NaiveStrategy.h \
    include/Piece.h \
    include/Player.h \
    include/QtBoardView.h \
    include/QtLabelClickable.h \
    include/Utils.h \

RESOURCES = \
    resources/images/images.qrc \

DESTDIR = gen/out
OBJECTS_DIR = obj
UI_DIR = gen/include
MOC_DIR = gen/src
RCC_DIR = gen/rcc

ICON = resources/tictactoe.ico

QMAKE_CXXFLAGS += -std=c++11
