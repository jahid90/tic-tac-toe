class Board {

public:

    char board[9];
    
	Board();
    virtual ~Board();
    
	void display_board();

	void update_board(int pos, char symbol);
    


};
