#ifndef MAZE_H
#define MAZE_H

#include "Block.h"
#include "Coord.h"
#include "Stack.h"

class Maze {

private:
    Block mMaze[16][16];
    //void FloodFill();
    void CalculateDistance();
    int CalculateManhattanDistance(int, int, int, int);
    int CalculateMinimum(int, int, int, int);
    Stack<Coord> GetNeighbors(Coord*);
    bool InGoal(Coord*);
    bool ReadNorthWall();
    bool ReadSouthWall();
    bool ReadEastWall();
    bool ReadWestWall();
    void SetWalls(Coord*);
public:
    Maze();
    void Initialize();
    Block(*GetMaze())[16]; // What the fuck.
    void PrintDistance();
    void FloodFill(); // Move to private later
	void breadth_first_search();
};

#endif