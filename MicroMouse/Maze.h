#ifndef MAZE_H
#define MAZE_H

#include "Block.h"
#include "Coord.h"
#include "Mouse.h"
#include "Stack.h"

class Maze {

private:
    Block mMaze[16][16];
    Mouse mMouse;
    Stack<Coord> mStack; // If using pointers, make sure to delete everything!
    //void FloodFill();
    void CalculateDistance();
    int CalculateManhattanDistance(int, int, int, int);
    int CalculateMinimum(int, int, int, int);
public:
    Maze();
    void Initialize();
    Block(*GetMaze())[16]; // What the fuck.
    void PrintDistance();
    void FloodFill(); // Move to private later
};

#endif