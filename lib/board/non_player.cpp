//
// Created by hosein on 12/15/23.
//

#include <algorithm>
#include "non_player.h"
#include "../random_gen.h"

NonPlayer::NonPlayer(int n, int m) : n(n), m(m) {
    number_of_foods = n * m;
    init_walls();
}

NonPlayer::NonPlayer(const NonPlayer &nonPlayer) {
    n = nonPlayer.n;
    m = nonPlayer.m;
    number_of_foods = nonPlayer.number_of_foods;
    board = new BaseBlock *[nonPlayer.n];
    for (int i = 0; i < nonPlayer.n; ++i) {
        board[i] = new BaseBlock[nonPlayer.m];
        for (int j = 0; j < nonPlayer.m; ++j) {
            board[i][j] = BaseBlock(nonPlayer.board[i][j]);
        }
    }
}

void NonPlayer::init_walls() {
    RandomGenerator generator(0, 10);
    board = new BaseBlock *[n];
    for (int i = 0; i < n; ++i) {
        board[i] = new BaseBlock[m];
        for (int j = 0; j < m; ++j) {
            if (generator.get_random() < NonPlayer::difficulty) {
                board[i][j] = BaseBlock(BlockType::WALL);
                number_of_foods--;
            } else {
                board[i][j] = BaseBlock(BlockType::FOOD);
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const NonPlayer &nonPlayer) {
    for (int i = 0; i < nonPlayer.n; ++i) {
        for (int j = 0; j < nonPlayer.m; ++j) {
            os << nonPlayer.board[i][j];
        }
        os << std::string("\n");

    }
    return os;
}

NonPlayer::~NonPlayer() {
    try {
        for (int i = 0; i < n; ++i) {
            delete[] board[i];
        }
        delete [] board;
    } catch(...) {

    }
}

NonPlayer &NonPlayer::operator=(const NonPlayer &other) noexcept {
    for (int i = 0; i < n; ++i) {
        delete [] board[i];
    }
    delete [] board;
    board = new BaseBlock*[other.n];
    for (int i = 0; i < other.n; ++i) {
        board[i] = new BaseBlock[other.m];
        std::copy_n(other.board[i], m, board[i]);
    }
    this->number_of_foods = other.number_of_foods;
    this->n = other.n;
    this->m = other.m;
    return *this;
}
