//
// Created by hosein on 12/15/23.
//

#ifndef PACMAN_CPP_RANDOM_GEN_H
#define PACMAN_CPP_RANDOM_GEN_H

#include "random"

using u32 = uint_least32_t;
using engine = std::mt19937;

class RandomGenerator {
public:

    std::random_device os_seed;
    const u32 seed = os_seed();
    engine generator;
    std::uniform_int_distribution<u32> distribution;

    int get_random();

    RandomGenerator(int a, int b);
};


#endif //PACMAN_CPP_RANDOM_GEN_H
