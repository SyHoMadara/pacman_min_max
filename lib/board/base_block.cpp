//
// Created by hosein on 12/15/23.
//
#include <iomanip>
#include "base_block.h"

BaseBlock::BaseBlock(BlockType blockType) : blockType(blockType) {

}

BaseBlock::BaseBlock(int blockType_int) {
    switch (blockType_int) {
        case 0:
            blockType = BlockType::EMPTY;
            break;
        case 1:
            blockType = BlockType::WALL;
            break;
        case 2:
            blockType = BlockType::FOOD;
            break;
        default:
            blockType = BlockType::EMPTY;
            break;
    }
}

BaseBlock::BaseBlock() {
    blockType = BlockType::EMPTY;
}

BaseBlock::BaseBlock(const BaseBlock &baseBlock) {
    blockType = baseBlock.blockType;
}

std::ostream &operator<<(std::ostream &os, const BaseBlock &baseBlock) {
    std::string outPut;
    switch (baseBlock.blockType) {
        case 0:
            outPut += " ";
            break;
        case 1:
            outPut += "|";
            break;
        case 2:
            outPut += "*";
            break;
    }
    os << outPut;
    return os;
}

BaseBlock &BaseBlock::operator=(const BaseBlock &other) noexcept = default;
