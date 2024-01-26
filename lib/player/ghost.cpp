//
// Created by hosein on 12/15/23.
//

#include "ghost.h"

Ghost::Ghost(int n, int m, int *position) : Player(n, m, position) {

}

Ghost::Ghost(const Ghost &ghost): Player((Player &) ghost) {

}

std::ostream &operator<<(std::ostream &os, const Ghost &ghost) {
    os << std::string(Ghost::symbol);
    return os;
}

Ghost::~Ghost() = default;

Ghost &Ghost::operator=(const Ghost &other) noexcept= default;


Ghost::Ghost() = default;
