#include <iostream>
#include "Block.h"
#include "Maze.h"

using namespace std;

int main() {
    Block block;
    cout << "Current: " << (int) block.GetBlock() << endl;
    block.Set(Block::Bits::WestWall, true);
    cout << "After Setting West Wall: " << (int)block.GetBlock() << endl;
    block.Set(Block::Bits::EastWall, true);
    cout << "After Setting East Wall: " << (int)block.GetBlock() << endl;
    cout << "Check West Wall Status: " << block.Get(Block::Bits::WestWall) << endl;
    block.Set(Block::Bits::WestWall, false);
    cout << "After Unsetting West Wall: " << (int)block.GetBlock() << endl;
    cout << "Check West Wall Status: " << block.Get(Block::Bits::WestWall) << endl;
    cout << "Check East Wall Status: " << block.Get(Block::Bits::EastWall) << endl;
    int x;

    Maze maze;
    maze.Initialize();
    maze.PrintDistance();


    cin >> x;
}