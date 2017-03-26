#include "Mouse.h"

Mouse::Mouse(unsigned char boardSize) : mBoardSize(boardSize), mPosition({0, 0}) {

}

const unsigned char* Mouse::GetPosition() {
    return mPosition;
}

void Mouse::SetPosition(unsigned char x, unsigned char y) {
    if (InBounds(x, y)) {
        mPosition[0] = x;
        mPosition[1] = y;
    }
}

bool Mouse::InBounds(unsigned char x, unsigned char y) {
    if (x >= 0 && x < mBoardSize && y >= 0 && y < mBoardSize) {
        return true;
    }
    return false;
}

void Mouse::MoveUp() {
    if (InBounds(mPosition[0] + 1, mPosition[1])) {
        mPosition[0] += 1;
    }
}

void Mouse::MoveDown() {
    if (InBounds(mPosition[0] - 1, mPosition[1])) {
        mPosition[0] -= 1;
    }
}

void Mouse::MoveLeft() {
    if (InBounds(mPosition[0], mPosition[1] - 1)) {
        mPosition[1] -= 1;
    }
}

void Mouse::MoveRight() {
    if (InBounds(mPosition[0], mPosition[1] + 1)) {
        mPosition[1] += 1;
    }
}