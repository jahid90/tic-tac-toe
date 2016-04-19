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
    src/helpers/BoardColumnIterator.cpp \
    src/helpers/BoardRowIterator.cpp \
    src/helpers/IBoardIterator.cpp \
    src/helpers/Utils.cpp \
    src/strategies/HumanStrategy.cpp \
    src/strategies/NaiveStrategy.cpp \
    src/views/ConsoleView.cpp \
    src/views/GuiView.cpp \
    src/views/QtBoardView.cpp \
    src/views/QtLabelClickable.cpp \
    src/GameController.cpp \
    $$files(gen/src/*.cpp) \

HEADERS += \
    include/Board.h \
    include/BoardActionsHelper.h \
    include/BoardRowIterator.h \
    include/BoardColumnIterator.h \
    include/Cell.h \
    include/CommonIncludes.h \
    include/GameController.h \
    include/IBoardIterator.h \
    include/IStrategy.h \
    include/IView.h \
    include/HumanStrategy.h \
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
