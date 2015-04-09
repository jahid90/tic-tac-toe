#include "includes.h"
#include "Board.h"

Board::Board() {
    for (int i = 0; i < 9; i++) {
        board[i] = '\0';
    }
}

Board::~Board() {
}

void Board::update_board(int pos, char symbol){
	board[pos]=symbol;
}

void Board::display_board() {
    cout << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << endl;
}



