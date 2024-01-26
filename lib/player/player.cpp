//
// Created by hosein on 12/15/23.
//

#include "player.h"
#include "../random_gen.h"
#include "algorithm"
#include "iostream"


Player::Player(int n, int m, int *position) : n(n), m(m) {
    init_position(position);
}

Player::Player(Player &player) {
    n = player.n;
    m = player.m;
    position = new int[2];
    std::copy_n(player.position, 2, position);
}

void Player::init_position(int *pos) {
    if (pos != nullptr) {
        position = pos;
        return;
    }
    RandomGenerator x_gen(0, n - 1);
    RandomGenerator y_gen(0, m - 1);
    int x = x_gen.get_random();
    int y = y_gen.get_random();
    position = new int[]{x, y};

}

void Player::move_left() const {
    updater(0, 1);
}

void Player::move_right() const {
    updater(0, -1);
}

void Player::move_up() const {
    updater(-1, 0);
}

void Player::move_down() const {
    updater(1, 0);
}

int *Player::next_pos(int x_change, int y_change) const {
    return new int[]{((position[0] + x_change) % n + n) % n, ((position[1] + y_change) % m + m) % m};
}

int *Player::next_pos(int *move) const {
    return next_pos(move[0], move[1]);
}

void Player::updater(int x_change, int y_change) const {
    position[0] = ((position[0] + x_change) % n + n) % n;
    position[1] = ((position[1] + y_change) % m + m) % m;
}

void Player::updater(int *move) const {
    updater(move[0], move[1]);
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << std::to_string(player.position[0]) << std::string(" ") << std::to_string(player.position[1]);
    return os;
}

bool Player::operator==(const Player &rhs) const {
    bool res = n == rhs.n &&
               m == rhs.m;
    for (int i = 0; i < 2; ++i) {
        res = res && (position[i] == rhs.position[i]);
    }
    return res;
}

bool Player::operator!=(const Player &rhs) const {
    return !(rhs == *this);
}

bool Player::operator==(const int *rhs) const {
    return (rhs[0] == position[0]) && (rhs[1] == position[1]);
}

Player::~Player() {
    try {
        delete[] position;
    } catch (...) {

    }
}

Player &Player::operator=(const Player &other) noexcept {
    if (this == &other) {
        return *this;
    }
    n = other.n;
    m = other.m;
    std::copy_n(other.position, 2, position);
    return *this;
}

Player::Player() {
    n = -1;
    m = -1;
    position = new int[]{-1, -1};
}








