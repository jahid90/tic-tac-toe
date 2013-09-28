#include "Board.h"
#include "Player.h"

class Engine {

	private:
        Human player;
        Computer comp;
        Board gameboard;
        char current_symbol;

    public:
        enum {
            START, PLAYING, QUIT, OWIN, XWIN, DRAW
        } state;
        Engine() {}
        Engine(Human _player,Computer _comp) {
            player = _player;
            comp = _comp;
            gameboard.display_board();
            state = PLAYING;
        }
        void update();
        void make_move(); 
        bool verify_move(int pos);  
		void find_winner(); 
        void display_result();	
        void check_game_state(char _board[]); 
        int evaluate_position(char _board[], char playerSymbol);  
        int get_state() { return state;}
};
