#ifndef __BOARD_H__
#define __BOARD_H__

class Board {
public:
    char board[9];

	Board();
    virtual ~Board();

	void display_board();

	void update_board(int pos, char symbol);
};

#endif  // __BOARD_H__
