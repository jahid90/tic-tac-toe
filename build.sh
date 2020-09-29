#!/bin/sh

echo "building..."

make clean
qmake TicTacToe.pro
./mk.sh
