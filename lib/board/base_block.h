//
// Created by hosein on 12/15/23.
//

#ifndef PACMAN_CPP_BASE_BLOCK_H
#define PACMAN_CPP_BASE_BLOCK_H
#include "ostream"

enum BlockType{
    FOOD = 2,
    WALL = 1,
    EMPTY = 0
};

class BaseBlock{
public:
    BlockType blockType;
    explicit BaseBlock(BlockType blockType);
    explicit BaseBlock(int blockType_int);
    BaseBlock(const BaseBlock& baseBlock);
    explicit BaseBlock();

    BaseBlock& operator=(const BaseBlock& other) noexcept;
    friend std::ostream &operator<<(std::ostream &os, const BaseBlock &baseBlock);

};

#endif //PACMAN_CPP_BASE_BLOCK_H
