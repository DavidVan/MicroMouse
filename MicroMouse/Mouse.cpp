#include "Mouse.h"

Mouse::Mouse(unsigned char boardSize) : mBoardSize(boardSize), mPosition{ { 15 },{ 1 } } {

}

const Coord Mouse::GetPosition() {
    return mPosition;
}

void Mouse::SetPosition(unsigned char x, unsigned char y) {
    
    Coord position(x, y);
    
    if (InBounds(position)) {
        mPosition.SetRow(x);
        mPosition.SetCol(y);
    }
}

bool Mouse::InBounds(Coord position) {
    if (position.GetRow() >= 0 && position.GetRow() < mBoardSize && position.GetCol() >= 0 && position.GetCol() < mBoardSize) {
        return true;
    }
    return false;
}

bool Mouse::InBounds(unsigned char x, unsigned char y)
{
    if (x >= 0 && x < mBoardSize && y >= 0 && y < mBoardSize) {
        return true;
    }
    return false;
}

void Mouse::MoveToCell(Coord cell)
{
    if (cell.GetCol() < mPosition.GetCol())
    {
        MoveLeft();
    }
    else
    {
        MoveRight();
    }
    if (cell.GetRow() < mPosition.GetRow())
    {
        MoveUp();
    }
    else
    {
        MoveDown();
    }
}

void Mouse::MoveUp() {
    if (InBounds(mPosition.GetRow() - 1, mPosition.GetCol())) {
        mPosition.MoveUp();
    }
}

void Mouse::MoveDown() {
    if (InBounds(mPosition.GetRow() + 1, mPosition.GetCol())) {
        mPosition.MoveDown();
    }
}

void Mouse::MoveLeft() {
    if (InBounds(mPosition.GetRow(), mPosition.GetCol() - 1)) {
        mPosition.MoveLeft();
    }
}

void Mouse::MoveRight() {
    if (InBounds(mPosition.GetRow(), mPosition.GetCol() + 1)) {
        mPosition.MoveRight();
    }
}

void Mouse::SetUpMaze() {
    // Modify walls of maze here
    completeMaze.Initialize();

}

void Mouse::ReadCell(Coord cellCoord, Block::Bits bit)
{
    completeMaze.mMaze[cellCoord.GetRow()][cellCoord.GetCol()] = bit;
}

bool Mouse::ReadNorthWall() {
    int row = mPosition.GetRow();
    int col = mPosition.GetCol();
    return completeMaze.GetMaze()[row][col].Get(Block::Bits::NorthWall);
}

bool Mouse::ReadSouthWall() {
    int row = mPosition.GetRow();
    int col = mPosition.GetCol();
    return completeMaze.GetMaze()[row][col].Get(Block::Bits::SouthWall);
}

bool Mouse::ReadEastWall() {
    int row = mPosition.GetRow();
    int col = mPosition.GetCol();
    return completeMaze.GetMaze()[row][col].Get(Block::Bits::EastWall);
}

bool Mouse::ReadWestWall() {
    int row = mPosition.GetRow();
    int col = mPosition.GetCol();
    return completeMaze.GetMaze()[row][col].Get(Block::Bits::WestWall);
}