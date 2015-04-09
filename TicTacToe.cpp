#include "includes.h"

#include "TicTacToe.h"

#include "Player.h"
#include "Engine.h"

TicTacToe::TicTacToe() {
}

void TicTacToe::startGame() {
    
	Human player("User");
    Computer comp("Computer");
    Engine control(player, comp);

    while (control.get_state() != control.QUIT) {
        while(control.get_state() == control.PLAYING) {
            control.make_move();
            control.update();
        }
        if (control.get_state()  == control.XWIN || control.get_state()  == control.OWIN || control.get_state()  == control.DRAW) {
            control.find_winner();
            control.display_result();
        }
    }
}
