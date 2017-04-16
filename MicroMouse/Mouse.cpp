#include "Mouse.h"

Mouse::Mouse(unsigned char boardSize) : mBoardSize(boardSize), mPosition{ { 0 },{ 0 } } {

}

Mouse::Mouse(unsigned char boardSize, unsigned char x, unsigned char y) : mBoardSize(boardSize), mPosition{ { x },{ y } } {

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
    if (InBounds(mPosition[0] - 1, mPosition[1])) {
        mPosition[0] -= 1;
    }
}

void Mouse::MoveDown() {
    if (InBounds(mPosition[0] + 1, mPosition[1])) {
        mPosition[0] += 1;
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

void Mouse::SetUpMaze() {
    // Modify walls of maze here
    completeMaze.Initialize();

}

bool Mouse::ReadNorthWall() {
    int row = mPosition[0];
    int col = mPosition[1];
    return completeMaze.GetMaze()[row][col].Get(Block::Bits::NorthWall);
}

bool Mouse::ReadSouthWall() {
    int row = mPosition[0];
    int col = mPosition[1];
    return completeMaze.GetMaze()[row][col].Get(Block::Bits::SouthWall);
}

bool Mouse::ReadEastWall() {
    int row = mPosition[0];
    int col = mPosition[1];
    return completeMaze.GetMaze()[row][col].Get(Block::Bits::EastWall);
}

bool Mouse::ReadWestWall() {
    int row = mPosition[0];
    int col = mPosition[1];
    return completeMaze.GetMaze()[row][col].Get(Block::Bits::WestWall);
}