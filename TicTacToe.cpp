#include "header.hpp"

TicTacToe::TicTacToe () {
	finished = false;
	MAXROW = 3;
	MAXCOL = 3;
	board = new char*[MAXROW];
	for (int i = 0; i < MAXROW; ++i) {
		board[i] = new char[MAXCOL];
		for (int j = 0; j < MAXCOL; ++j) {
			board[i][j] = '#';
		}
	}
}

void TicTacToe::printBoard () {
	cout << endl;
	for (int i = 0; i < MAXROW; ++i) {
		for (int j = 0; j < MAXCOL; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void TicTacToe::playerOneMove (int x, int y) {

}

void TicTacToe::playerTwoMove (int x, int y) {

}