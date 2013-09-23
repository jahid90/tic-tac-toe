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