#include <iostream>
#include "Block.h"
#include "Stack.h"
#include "Maze.h"
#include "Coord.h"

using namespace std;

int main() {
	Block block;
	cout << "Current: " << (int)block.GetBlock() << endl;
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

	cout << endl << endl << endl;

	maze.FloodFill();
	maze.PrintDistance();

	/*Stack<Coord*> stack;
	cout << "Initialized?: " << stack.size() << endl;

	for (int i = 0; i < 17; i++) {
	cout << i << endl;
	Coord *t = new Coord(i, i);
	stack.push(t);
	}

	cout << "Stack size: " << stack.size() << endl;

	Coord *item = stack.pop();

	cout << "Item: " << (int)(item->GetRow()) << endl;

	delete item;

	cout << "Item: " << (int)(item->GetRow()) << endl;

	cout << "Stack size: " << stack.size() << endl;*/

	system("pause");
	
	return 0;
}