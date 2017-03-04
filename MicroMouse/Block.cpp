#include "Block.h"

Block::Block() : mBlock(0), mDistance(0) {

}

void Block::Set(Bits bit, bool exists) {
    if (exists) {
        mBlock |= (1 << bit);
    }
    else {
        mBlock &= ~(1 << bit);
    }
}

void Block::SetDistance(unsigned char distance) {
    mDistance = distance;
}

bool Block::Get(Bits bit) {
    return (mBlock >> bit) & 1; // Should only return 0 or 1...
}

unsigned char Block::GetBlock() {
    return mBlock;
}

unsigned char Block::GetDistance() {
    return mDistance;
}