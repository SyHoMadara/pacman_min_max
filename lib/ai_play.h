//
// Created by hosein on 12/23/23.
//

#ifndef PACMAN_CPP_AI_PLAY_H
#define PACMAN_CPP_AI_PLAY_H

#include "init_config.h"
#include "board/game_board.h"
#include "random_gen.h"

class AiPlay : public GameBoard {
public:
    constexpr static int RIGHT[] = {0, 1};
    constexpr static int LEFT[] = {0, -1};
    constexpr static int UP[] = {-1, 0};
    constexpr static int DOWN[] = {1, 0};
    int minimizer;

    int last_move;

    static RandomGenerator rgen;

    unsigned depth;

    explicit AiPlay();

    AiPlay(const AiPlay &aiPlay);

    int *determine_pacman_move() override;

    int *determine_ghost_move(int i_th) override;

    int value(const AiPlay& state, bool is_min=false);

    int max_value(const AiPlay& state);

    int min_value(const AiPlay& state);

    static int *move(int i);

    friend std::ostream &operator<<(std::ostream &os, const AiPlay& aiPlay);

    AiPlay& operator=(const AiPlay& other) noexcept;

    [[nodiscard]] bool isTerminalState() const;

};


#endif //PACMAN_CPP_AI_PLAY_H
