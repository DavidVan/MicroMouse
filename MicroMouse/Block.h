#ifndef BLOCK_H
#define BLOCK_H

class Block {

    // ---------------------------------
    // | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
    // ---------------------------------
    //   ^   ^   ^   ^   ^   ^   ^   ^
    //   |   |   |   |   |   |   |   |--- Not Visited Flag
    //   |   |   |   |   |   |   |--- Visited
    //   |   |   |   |   |   |--- UNUSED
    //   |   |   |   |   |--- UNUSED
    //   |   |   |   |--- West Wall Flag
    //   |   |   |--- East Wall Flag
    //   |   |--- South Wall Flag
    //   |--- North Wall Flag

private:
    unsigned char mBlock; // Holds the flags.
    unsigned char mDistance; // Distance to center.

public:
    Block();

    enum Bits {
        NorthWall = 7,
        SouthWall = 6,
        EastWall = 5,
        WestWall = 4,
        Not_Passable = 2,
        Passable = 1,
        Not_Visited = 0
    };

    void Set(Bits, bool); // Used to set various flags (above).
    void SetDistance(unsigned char);

    bool Get(Bits); // Used to get various flags (above).
    unsigned char GetBlock();
    unsigned char GetDistance();

};

#endif