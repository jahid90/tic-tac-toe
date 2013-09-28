#include <list>
#include <stdlib.h>
#include "Engine.h"

using namespace std;

class Minimax {

private:
    static const int INFINITY = 10000;
	Engine control;

public:
    
    Minimax(){}
    list<int> generate_moves(char _board[]);

    int evaluate_board(char _board[]);
    int MiniMax(char _board[]);
    int MinMove(char _board[]);
    int MaxMove(char _board[]);

};
