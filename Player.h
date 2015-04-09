#include "header.h"

class Player {

private:

	string playerName;
	char playerSymbol;
	int move;

	bool win;
	bool isTurn;

public:

    Player() {}
    Player(string name, char symbol) : playerName(name), playerSymbol(symbol),win(false) {}

    char getPlayerSymbol() {
        return playerSymbol;
    }

    string getPlayerName() {
        return playerName;
    };

    bool is_win() {
        return win;
    }

    void setWin(bool sWin) {
        win = sWin;
    }

    bool is_turn() {
        return isTurn;
    }

    void setTurn(bool sTurn) {
        isTurn = sTurn;
    }

    void set_move(int pos ) {

        move = pos;
    }

    int get_move() { 
	
		return move;
	}

};

class Computer : public Player {
public:
    Computer(){}

    Computer(std::string name, char symbol = 'O') : Player(name, symbol)
	{

    }
};

class Human : public Player {

public:
    Human(){}
    Human(string name, char symbol = 'X') : Player(name, symbol) {}

    int ask_move(){
		
		int pos = -1;
		cin >> pos;
		pos--;
		return pos;	
	};

};
