#include <iostream>
#include "Engine.h"
#include "Minimax.h"
using namespace std;

void Engine::make_move()
{
    if (player.is_turn()) {
        int pos = player.ask_move();
        while (!verify_move(pos)) {
            pos = player.ask_move();
        }
        gameboard.update_board(pos,player.getPlayerSymbol());
        current_symbol = player.getPlayerSymbol();
        player.setTurn(false);
        comp.setTurn(true);
    } else {
        Minimax minimax;
        int pos = minimax.MiniMax(gameboard.board);
        cout << "Computer move" << pos << endl;
        gameboard.update_board(pos,comp.getPlayerSymbol());
        current_symbol = comp.getPlayerSymbol();
        comp.setTurn(false);
        player.setTurn(true);
    }
    state = PLAYING;
}

bool Engine::verify_move(int pos)
{
    if (gameboard.board[pos] != '\0' || (pos < 0) || (pos > 9)) {
        cout << "Invalid move" << endl;
        return false;
    }
    return true;
}

void Engine::check_game_state(char _board[]) {

    if ((_board[0] == current_symbol && _board[1] == current_symbol && _board[2] == current_symbol) ||
		(_board[3] == current_symbol && _board[4] == current_symbol && _board[5] == current_symbol) ||
		(_board[6] == current_symbol && _board[7] == current_symbol && _board[8] == current_symbol) ||
		(_board[0] == current_symbol && _board[3] == current_symbol && _board[6] == current_symbol) ||
		(_board[1] == current_symbol && _board[4] == current_symbol && _board[7] == current_symbol) ||
		(_board[2] == current_symbol && _board[5] == current_symbol && _board[8] == current_symbol) ||
		(_board[0] == current_symbol && _board[4] == current_symbol && _board[8] == current_symbol) ||
		(_board[2] == current_symbol && _board[4] == current_symbol && _board[6] == current_symbol))
	{
        if (current_symbol == 'X')
        {
            state = XWIN;
        }
        else if (current_symbol == 'O')
        {
            state = OWIN;
        }
	}
	else
	{
	    state = DRAW;
		for(int i = 0; i < 9; ++i) {
			if(_board[i] == 0) {
				state = PLAYING;
				break;
			}
		}
	}
}

void Engine::find_winner(){
    if (state == XWIN) {
        player.setWin(true);
    } else if (state == OWIN) {
        comp.setWin(true);
    }
}

void Engine::display_result() {
    if(player.is_win()) {
		cout << player.getPlayerName() << " has won the game!" << endl;
	} else if(comp.is_win()) {
		cout << comp.getPlayerName() << " has won the game!" << endl;
	} else {
		cout << "no winner, this game is a draw." << endl;
	}
	state = QUIT;
}

void Engine::update() {
    gameboard.display_board();
    check_game_state(gameboard.board);
}