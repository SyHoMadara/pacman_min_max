//
// Created by hosein on 12/23/23.
//

#include <climits>
#include <iostream>
#include "ai_play.h"
#include "init_config.h"
#include "base4.h"

RandomGenerator AiPlay::rgen(0, 3);

AiPlay::AiPlay() : GameBoard(
        InitConfig::N,
        InitConfig::M,
        InitConfig::REFRESH_RETE,
        InitConfig::DISPLAY_SCALE,
        InitConfig::NUMBER_OF_GHOSTS) {
    depth = InitConfig::DEPTH;
    minimizer = 0;
}

AiPlay::AiPlay(const AiPlay &aiPlay) : GameBoard((GameBoard &) aiPlay) {
    depth = aiPlay.depth;
}

int *AiPlay::determine_pacman_move() {
    value(*this);
    return AiPlay::move(last_move);
}

int *AiPlay::determine_ghost_move(int i_th) {
    return move(rgen.get_random());
}

int AiPlay::value(const AiPlay& state, bool is_min) {
    if (state.isTerminalState()) {
        return state.pacman.score;
    }
    if (is_min) {
        return min_value(state);
    } else {
        return max_value(state);
    }
}

int AiPlay::max_value(const AiPlay& state) {
    int v = INT_MIN;
    int move = -1;
    RandomGenerator gen(0,100);
    for (int i = 0; i < 3; i++) {
        auto thisMove = AiPlay::move(i);
        AiPlay newState = state;
        newState.pacman_play(thisMove);
        newState.depth--;
        auto res = value(newState, true);
        if (v < res){
            move = i;
            v = res;
        }
        if (res != INT_MIN and gen.get_random()<=10){
            last_move = i;
            break;
        }
    }
    last_move = move;
    return v;
}

int AiPlay::min_value(const AiPlay& state) {
    int v = INT_MAX;
//    for(int i=0;i < (1<<ghosts.size()); i++){
    for (int i = 0; i < 4; ++i) {
//        Base4 move(i, (int) ghosts.size());
        AiPlay newState = state;
        newState.depth--;
//        for(int j = 0; j < ghosts.size(); j++){
//            newState.ghost_play(j, AiPlay::move(move.representation[j]));
//        }
        newState.ghost_play(state.minimizer%(2), move(i));
        newState.minimizer ^= 1;
        auto res = value(newState, newState.minimizer%2);
        if (v > res){
            v = res;
        }
    }
    return v;
}

bool AiPlay::isTerminalState() const {
    return is_end() || depth == 0 || !pacman.is_alive;
}

int *AiPlay::move(int i) {
    switch (i) {
        case 0:
            return const_cast<int *>(AiPlay::RIGHT);
        case 1:
            return const_cast<int *>(AiPlay::LEFT);
        case 2:
            return const_cast<int *>(AiPlay::UP);
        case 3:
            return const_cast<int *>(AiPlay::DOWN);
        default:
            return const_cast<int *>(AiPlay::RIGHT);
    }
}

std::ostream &operator<<(std::ostream &os, const AiPlay &aiPlay) {
    os << (GameBoard &) aiPlay;
    return os;
}

AiPlay &AiPlay::operator=(const AiPlay &other) noexcept= default;


