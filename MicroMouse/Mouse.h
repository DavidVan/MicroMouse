#ifndef MOUSE_H
#define MOUSE_H

#include "Maze.h"
#include "Block.h"
#include "Coord.h"

class Mouse {
    
    // Representation of a mouse in lieu of the real thing.

private:
    Maze completeMaze; // Internal representation of the maze, complete with wall information.
    unsigned char mBoardSize;
    Coord mPosition;
    bool InBounds(Coord);
    bool InBounds(unsigned char, unsigned char);
    void SetUpMaze();
public:
    Mouse(unsigned char);
    const Coord GetPosition();
    void SetPosition(unsigned char, unsigned char);
    void MoveToCell(Coord);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void ReadCell(Coord);
    bool ReadNorthWall();
    bool ReadSouthWall();
    bool ReadEastWall();
    bool ReadWestWall();
};

#endif