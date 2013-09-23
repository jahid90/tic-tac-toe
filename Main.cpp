#include <iostream>
#include <cstdlib>

using namespace std;

class TicTacToe {
private:
	bool finished;
	int MAXROW;
	int MAXCOL;
	char **board;
public:
	// constructors and destructors
	TicTacToe();

	// onject methods
	void printBoard();
	void playerOneMove (int x, int y);
	void playerTwoMove (int x, int y);
};

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

int main (int argc, char **argv) {
	cout << "*******TIC-TAC-TOE*******" << endl;

	TicTacToe game;

	game.printBoard();
	
	return EXIT_SUCCESS;
}