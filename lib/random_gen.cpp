//
// Created by hosein on 12/15/23.
//

#include "random_gen.h"

RandomGenerator::RandomGenerator(int a, int b) {
    generator = engine(seed);
    distribution = std::uniform_int_distribution<u32>(a, b);
}

int RandomGenerator::get_random() {
    return (int) distribution(generator);
}
