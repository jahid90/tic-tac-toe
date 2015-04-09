#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player {

private:

    string  playerName;
    char    playerSymbol;
    int     move;

    bool    win;
    bool    isTurn;

public:

    Player();
    Player(string name, char symbol);

    char    getPlayerSymbol ();
    string  getPlayerName   ();
    bool    is_win          ();
    void    set_win          (bool sWin);
    bool    is_turn         ();
    void    setTurn         (bool sTurn);
    void    set_move        (int pos);
    int     get_move        ();
};

class Computer : public Player {

public:

    Computer();
    Computer(string name, char symbol = 'O');
};

class Human : public Player {

public:

    Human();
    Human(string name, char symbol = 'X');

    int     ask_move        ();
};

#endif  // __PLAYER_H__
