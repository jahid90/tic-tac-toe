#include "includes.h"
#include "Player.h"

// Player

Player::Player() {
}

Player::Player(string name, char symbol) {
    playerName      =   name;
    playerSymbol    =   symbol;
    win             =   false;
}

char Player::getPlayerSymbol() { return playerSymbol; }

string Player::getPlayerName () { return playerName; };

bool Player::is_win () { return win; }

void Player::set_win (bool sWin) { win = sWin; }

bool Player::is_turn () { return isTurn; }

void Player::setTurn (bool sTurn) { isTurn = sTurn; }

void Player::set_move (int pos) { move = pos; }

int Player::get_move () { return move; }

// Computer

Computer::Computer() {
}

Computer::Computer(string name, char symbol) : Player(name, symbol) {
}

// Human

Human::Human() {
}

Human::Human(string name, char symbol) : Player(name, symbol) {
}

int Human::ask_move(){

    cout << "Enter your move: ";

    int pos = -1;

    cin >> pos;
    pos--;
    
    return pos; 
};