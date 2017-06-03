#include <iostream>
#include <cmath>
#include "Maze.h"

using namespace std;

Maze::Maze() {
    Initialize();
}

void Maze::Initialize() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (i == 0 || i == 15 || j == 0 || j == 15) {
                if (i == 0) { // Top of maze.
                    mMaze[i][j].Set(Block::Bits::NorthWall, true);
                    mMaze[i][j].Set(Block::Bits::SouthWall, false);
                }
                else if (i == 15) { // Bottom of maze.
                    mMaze[i][j].Set(Block::Bits::NorthWall, false);
                    mMaze[i][j].Set(Block::Bits::SouthWall, true);
                }
                else {
                    mMaze[i][j].Set(Block::Bits::NorthWall, false);
                    mMaze[i][j].Set(Block::Bits::SouthWall, false);
                }
                if (j == 0) { // Left of maze.
                    mMaze[i][j].Set(Block::Bits::EastWall, false);
                    mMaze[i][j].Set(Block::Bits::WestWall, true);
                }
                else if (j == 15) { // Right of maze.
                    mMaze[i][j].Set(Block::Bits::EastWall, true);
                    mMaze[i][j].Set(Block::Bits::WestWall, false);
                }
                else {
                    mMaze[i][j].Set(Block::Bits::EastWall, false);
                    mMaze[i][j].Set(Block::Bits::WestWall, false);
                }
                mMaze[i][j].SetDistance(-1);
            }
            else if ((i == 7 || i == 8) && (j == 7 || j == 8)) { // Center of maze.
                mMaze[i][j].Set(Block::Bits::NorthWall, false);
                mMaze[i][j].Set(Block::Bits::SouthWall, false);
                mMaze[i][j].Set(Block::Bits::EastWall, false);
                mMaze[i][j].Set(Block::Bits::WestWall, false);
                mMaze[i][j].SetDistance(0);
            }
            else { // Other areas of maze.
                mMaze[i][j].Set(Block::Bits::NorthWall, false);
                mMaze[i][j].Set(Block::Bits::SouthWall, false);
                mMaze[i][j].Set(Block::Bits::EastWall, false);
                mMaze[i][j].Set(Block::Bits::WestWall, false);
                mMaze[i][j].SetDistance(-1);
            }
            mMaze[i][j].Set(Block::Bits::Visited, false);
        }
    }
    CalculateDistance();
}

Block(*Maze::GetMaze())[16] { // What the fuck.
    return mMaze;
}

void Maze::FloodFill() {
    Stack<Coord> cellsToCheck; // If using pointers, make sure to delete everything!

    Coord mousePos(15, 0); // Row, Col - Starting is bottom left corner.

    int row = mousePos.GetRow();
    int col = mousePos.GetCol();

    int currentDistance = mMaze[row][col].GetDistance();
    
    // Read and Set Walls
    SetWalls(&mousePos);
    
    // Start the process
    cellsToCheck.push(mousePos);

    // Rinse and Repeat
    while (!InGoal(&mousePos)) {
        while (!cellsToCheck.empty()) {
            Coord cell = cellsToCheck.pop();
            row = cell.GetRow();
            col = cell.GetCol();

            if ((currentDistance - mMaze[row][col].GetDistance()) == 1) {

            }
            else {

            }
        }
    }
}

bool Maze::InGoal(Coord* mousePos) {
    int row = mousePos->GetRow();
    int col = mousePos->GetCol();

    return (row == 7 && col == 7) || (row == 7 && col == 8) || (row == 8 && col == 7) || (row == 8 && col == 8);
}

void Maze::SetWalls(Coord* mousePos) {
    int row = mousePos->GetRow();
    int col = mousePos->GetCol();

    mMaze[row][col].Set(Block::Bits::NorthWall, ReadNorthWall());
    mMaze[row][col].Set(Block::Bits::SouthWall, ReadSouthWall());
    mMaze[row][col].Set(Block::Bits::EastWall, ReadEastWall());
    mMaze[row][col].Set(Block::Bits::WestWall, ReadWestWall());
}


// Update the ReadWall functions to interface with the mouse later.
bool Maze::ReadNorthWall() {
    return true;
}

bool Maze::ReadSouthWall() {
    return true;
}

bool Maze::ReadEastWall() {
    return true;
}

bool Maze::ReadWestWall() {
    return true;
}

void Maze::CalculateDistance() {
    // Objective is (7, 7), (7, 8), (8, 7), or (8, 8).
    // Calculate manhattan distance and use shortest one.
    int cornerOne = 7;
    int cornerTwo = 8;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            mMaze[i][j].SetDistance(
                CalculateMinimum(
                    CalculateManhattanDistance(i, j, cornerOne, cornerOne),
                    CalculateManhattanDistance(i, j, cornerOne, cornerTwo),
                    CalculateManhattanDistance(i, j, cornerTwo, cornerOne),
                    CalculateManhattanDistance(i, j, cornerTwo, cornerTwo)
                )
            );
        }
    }
}

int Maze::CalculateManhattanDistance(int currentX, int currentY, int objectiveX, int objectiveY) {
    return abs(currentX - objectiveX) + abs(currentY - objectiveY);
}

int Maze::CalculateMinimum(int a, int b, int c, int d) {
    int minimum = a;
    if (b < minimum) {
        minimum = b;
    }
    if (c < minimum) {
        minimum = c;
    }
    if (d < minimum) {
        minimum = d;
    }
    return minimum;
}

void Maze::PrintDistance() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (mMaze[i][j].GetDistance() >= 10) {
                printf("%d ", mMaze[i][j].GetDistance());
            }
            else {
                printf(" %d ", mMaze[i][j].GetDistance());
            }
        }
        printf("\n");
    }
}