//
// Created by hosein on 12/15/23.
//

#ifndef PACMAN_CPP_GAME_BOARD_H
#define PACMAN_CPP_GAME_BOARD_H

#include "non_player.h"
#include "ostream"
#include "../player/pacman.h"
#include "../player/ghost.h"

class GameBoard {
public:
    int n;
    int m;
    int refresh_rate;
    int scale;
    NonPlayer nonPlayer;
    Pacman pacman;
    std::vector<Ghost> ghosts;

    GameBoard(int n, int m, int refresh_rate, int scale,int number_of_ghost);

    GameBoard(const GameBoard &gameBoard);

    bool playable();

    void fix_board();

    void pacman_auto_play();

    void pacman_play(int *move);

    virtual int *determine_pacman_move();

    void ghost_auto_play(int i_th);

    void ghost_play(int i_th, int *move);

    virtual int *determine_ghost_move(int i_th);

    void start(std::ostream &os);

    bool is_end() const;

    friend std::ostream &operator<<(std::ostream &os, const GameBoard &gameBoard);

    GameBoard& operator=(const GameBoard& other) noexcept;

    virtual ~GameBoard();

};


#endif //PACMAN_CPP_GAME_BOARD_H
