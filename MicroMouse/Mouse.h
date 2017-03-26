#ifndef MOUSE_H
#define MOUSE_H

class Mouse {
    
    // Representation of a mouse in lieu of the real thing.

private:
    unsigned char mBoardSize;
    unsigned char mPosition[2]; // [0] = X Coordinate, [1] = Y Coordinate
    bool InBounds(unsigned char, unsigned char);
public:
    Mouse();
    Mouse(unsigned char);
    const unsigned char* GetPosition();
    void SetPosition(unsigned char, unsigned char);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
};

#endif