#!/usr/bin/sh

make clean
qmake-qt5 TicTacToe.pro
make
./gen/out/tictactoe
