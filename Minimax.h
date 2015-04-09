#ifndef __MINIMAX_H__
#define __MINIMAX_H__

//class Engine;

class Minimax {

private:
    static const int INFINITY = 10000;
	//Engine *control;

public:
    
    Minimax();
    list<int> generate_moves(char _board[]);

    int evaluate_board(char _board[]);
    int MiniMax(char _board[]);
    int MinMove(char _board[]);
    int MaxMove(char _board[]);

};

#endif  // __MINIMAX_H__
