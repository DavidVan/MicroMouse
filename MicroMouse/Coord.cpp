#include "Coord.h"

Coord::Coord() {

}

Coord::Coord(unsigned char row, unsigned char col) : row(row), col(col) {

}

Coord::~Coord() {

}

void Coord::SetRow(unsigned char row) {
    row = row;
}

void Coord::SetCol(unsigned char col) {
    col = col;
}

unsigned char Coord::GetRow() {
    return row;
}

unsigned char Coord::GetCol() {
    return col;
}

bool Coord::MoveUp() {
    if (InBounds(row - 1, col)) {
        row -= 1;
        return true;
    }
    return false;
}

bool Coord::MoveDown() {
    if (InBounds(row + 1, col)) {
        row += 1;
        return true;
    }
    return false;
}

bool Coord::MoveLeft() {
    if (InBounds(row, col - 1)) {
        col -= 1;
        return true;
    }
    return false;
}

bool Coord::MoveRight() {
    if (InBounds(row, col + 1)) {
        col += 1;
        return true;
    }
    return false;
}

bool Coord::InBounds(unsigned char row, unsigned char col) {
    return row >= 0 && row < 16 && col >= 0 && col < 16; // Board size is 16
}