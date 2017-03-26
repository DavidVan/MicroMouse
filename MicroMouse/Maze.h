#ifndef MAZE_H
#define MAZE_H

#include "Block.h"
#include "Mouse.h"
#include "Stack.h"

class Maze {
private:
    Block mMaze[16][16];
    Mouse mMouse;
    // Stack</*Data Type Here*/> mStack;
    void FloodFill();
    void CalculateDistance();
    int CalculateManhattanDistance(int, int, int, int);
    int CalculateMinimum(int, int, int, int);
public:
    void Initialize();
    Block(*GetMaze())[16]; // What the fuck.
    void PrintDistance();
};

#endif