//
// Created by hosein on 12/15/23.
//

#include "pacman.h"

Pacman::Pacman(int n, int m, int *position) : Player(n, m, position) {
    is_alive = true;
    score = 0;
}

Pacman::Pacman(const Pacman &pacman) : Player((Player &) pacman) {
    is_alive = pacman.is_alive;
    score = pacman.score;
}

std::ostream &operator<<(std::ostream &os, const Pacman &pacman) {
    os << std::string(Pacman::symbol);
    return os;
}

Pacman::~Pacman() = default;

Pacman &Pacman::operator=(const Pacman &other) noexcept = default;
