#include "header.h"

list<int> Minimax::generate_moves(char _board[]) {
    list<int> list;
   
	for (int i = 0; i < 9; ++i) {
   
		if (_board[i] == 0) {
        
			list.push_back(i);
       
		}
   
	}
	return list;

}

int Minimax::evaluate_board(char _board[]) {
    char symbol ='*';
    if ((_board[0] == _board[1] || _board[1] == _board[2]) && (_board[1] != '\0')) {
        symbol = _board[1];
    }
    if (((_board[3] == _board[4] || _board[4] == _board[5]) && (_board[4] != '\0')) ||
    ((_board[1] == _board[4] || _board[4] == _board[7]) && (_board[4] != '\0')) ||
    ((_board[0] == _board[4] || _board[4] == _board[8]) && (_board[4] != '\0')) ||
    ((_board[2] == _board[4] || _board[4] == _board[6]) && (_board[4] != '\0'))) {
        symbol = _board[4];
    }
    if ((_board[6] == _board[7] || _board[7] == _board[8]) && (_board[7] != '\0')) {
        symbol = _board[7];
    }
    if ((_board[0] == _board[3] || _board[3] == _board[6]) && (_board[3] != '\0')) {
        symbol = _board[3];
    }
    if ((_board[2] == _board[5] || _board[5] == _board[8]) && (_board[5] != '\0')) {
        symbol = _board[5];
    }
    if (symbol == 'X')
    {
        return INFINITY;
    }
    else if (symbol == 'O')
    {
        return -INFINITY;
	}
	else
	{
	    return 0;
	}
    return -1; 
}

// returns best move for the current computer player
int Minimax::MiniMax(char _board[])
{
    int index = 0;
	int nBestScore = -INFINITY; 
	vector<int> nBestMoves; 

    list<int> nValidMoves;
	nValidMoves = generate_moves(_board); 

	while(!(nValidMoves.empty())) 
	{
	    _board[nValidMoves.front()] = 'O'; 
		int nScore = MinMove(_board);  
		if(nScore > nBestScore)
		{
			nBestScore = nScore;  
			nBestMoves.clear(); 
			nBestMoves.push_back(nValidMoves.front()); 
		}
		else if (nScore == nBestScore)
		{
			nBestMoves.push_back(nValidMoves.front());  
		}
		_board[nValidMoves.front()] = 0; 
		nValidMoves.pop_front();  
	}

	index = nBestMoves.size();
	cout << "Index" << index << endl;
    if (index > 0) {
        index = rand() % index;
   }
	return (nBestMoves[index]);  
}

int Minimax::MinMove(char _board[])
{
	int nMoveScore = evaluate_board(_board);
	if(!(nMoveScore == -1))  return nMoveScore;  

	int nBestScore = INFINITY; 
	list<int> nValidMoves;
	nValidMoves = generate_moves(_board);

	while(!(nValidMoves.empty()))
	{
		_board[nValidMoves.front()] = 'X';

		int nScore = MaxMove(_board); 

		if(nScore < nBestScore)
		{
			nBestScore = nScore;
		}
		_board[nValidMoves.front()] = 0; 
		nValidMoves.pop_front();
	}

	return nBestScore;
}

int Minimax::MaxMove(char _board[])
{
	int nMoveScore = evaluate_board(_board);
	if(!(nMoveScore == -1))  return nMoveScore;  

	int nBestScore = -INFINITY; 
	list<int> nValidMoves;
	nValidMoves = generate_moves(_board);

	while(!(nValidMoves.empty()))
	{
		_board[nValidMoves.front()] = 'O'; 
		int nScore = MinMove(_board); 

		if(nScore > nBestScore)
		{
			nBestScore = nScore;
		}
		_board[nValidMoves.front()] = 0; 
		nValidMoves.pop_front();
	}

	return nBestScore;
}