#!/usr/bin/sh

echo "building..."

make clean
qmake-qt5 TicTacToe.pro
./mk.sh
