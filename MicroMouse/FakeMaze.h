#ifndef FAKEMAZE_H
#define FAKEMAZE_H

#include "Block.h"
#include "Mouse.h"
#include "Stack.h"

class FakeMaze {

// Not a real maze. This will hold a test maze for use with the test mouse.

private:
    Block mMaze[16][16];
    void CalculateDistance();
    int CalculateManhattanDistance(int, int, int, int);
    int CalculateMinimum(int, int, int, int);
public:
    FakeMaze();
    void Initialize();
    Block(*GetMaze())[16]; // What the fuck.
    void PrintDistance();
};

#endif