//
// Created by hosein on 12/15/23.
//

#ifndef PACMAN_CPP_PLAYER_H
#define PACMAN_CPP_PLAYER_H
#include "../random_gen.h"

class Player {
public:
    int n;
    int m;
    int *position;

    Player(int n, int m, int *position = nullptr);
    Player();

    Player(Player &player);

    void init_position(int *pos);

    void move_left() const;

    void move_right() const;

    void move_up() const;

    void move_down() const;

    [[nodiscard]] int* next_pos(int x_change, int y_change) const;
    int* next_pos(int *move) const;

    void updater(int x_change, int y_change) const;

    friend std::ostream &operator<<(std::ostream &os, const Player & player);

    bool operator==(const Player &rhs) const;
    bool operator==(const int* rhs) const;


    bool operator!=(const Player &rhs) const;

    void updater(int *move) const;

    Player& operator=(const Player& other) noexcept;

    virtual ~Player();
};


#endif //PACMAN_CPP_PLAYER_H
