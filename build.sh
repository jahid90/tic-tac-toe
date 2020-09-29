#!/bin/sh

echo "building..."

# Clean any previous artifacts
make clean

# Generate the Makefile
qmake TicTacToe.pro

# Build the project
make
