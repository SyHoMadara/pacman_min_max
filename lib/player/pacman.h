//
// Created by hosein on 12/15/23.
//

#ifndef PACMAN_CPP_PACMAN_H
#define PACMAN_CPP_PACMAN_H
#include "player.h"

class Pacman: public Player{
public:
    int score;
    bool is_alive;
    constexpr static const char symbol[] = "P";
    Pacman(int n, int m, int *position= nullptr);

    Pacman(const Pacman &pacman);

    Pacman& operator=(const Pacman& other) noexcept;

    friend std::ostream &operator<<(std::ostream &os, const Pacman & pacman);

    ~Pacman() override;
};


#endif //PACMAN_CPP_PACMAN_H
