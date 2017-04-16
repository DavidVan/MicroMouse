#ifndef MOUSE_H
#define MOUSE_H

#include "FakeMaze.h"

class Mouse {
    
    // Representation of a mouse in lieu of the real thing.

private:
    FakeMaze completeMaze; // Internal representation of the maze, complete with wall information.
    unsigned char mBoardSize;
    unsigned char mPosition[2]; // [0] = Row, [1] = Column
    bool InBounds(unsigned char, unsigned char);
    void SetUpMaze();
public:
    Mouse(unsigned char);
    Mouse(unsigned char, unsigned char, unsigned char);
    const unsigned char* GetPosition();
    void SetPosition(unsigned char, unsigned char);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    bool ReadNorthWall();
    bool ReadSouthWall();
    bool ReadEastWall();
    bool ReadWestWall();
};

#endif