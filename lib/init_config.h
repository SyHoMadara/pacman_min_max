//
// Created by hosein on 12/23/23.
//

#ifndef PACMAN_CPP_INIT_CONFIG_H
#define PACMAN_CPP_INIT_CONFIG_H

enum InitConfig{
    N = 9,
    M = 18,
    NUMBER_OF_GHOSTS = 2,
    DISPLAY_SCALE = 3,
    REFRESH_RETE = 100,
    DEPTH = 3
};

class Move{
    const static int** MOVES;
};


#endif //PACMAN_CPP_INIT_CONFIG_H
