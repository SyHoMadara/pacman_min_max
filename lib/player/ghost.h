//
// Created by hosein on 12/15/23.
//

#ifndef PACMAN_CPP_GHOST_H
#define PACMAN_CPP_GHOST_H
#include "player.h"

class Ghost: public Player {
public:
    Ghost();

    constexpr static const char symbol[] = "G";
    Ghost(int n, int m, int *position = nullptr);

    Ghost(const Ghost &ghost);

    Ghost& operator=(const Ghost& other) noexcept;

    friend std::ostream &operator<<(std::ostream &os, const Ghost &ghost);

    ~Ghost() override;
};


#endif //PACMAN_CPP_GHOST_H
