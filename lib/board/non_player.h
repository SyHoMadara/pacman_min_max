//
// Created by hosein on 12/15/23.
//

#ifndef PACMAN_CPP_NON_PLAYER_H
#define PACMAN_CPP_NON_PLAYER_H
#include "base_block.h"
#include "ostream"

class NonPlayer {   
public:

    static const int difficulty = 2;

    int n;
    int m;
    BaseBlock **board;
    int number_of_foods;

    NonPlayer(int n, int m);
    NonPlayer(const NonPlayer& nonPlayer);

    void init_walls();

    friend std::ostream &operator<<(std::ostream &os, const NonPlayer &nonPlayer);

    NonPlayer& operator=(const NonPlayer& other) noexcept;

    virtual ~NonPlayer();
};


#endif //PACMAN_CPP_NON_PLAYER_H
