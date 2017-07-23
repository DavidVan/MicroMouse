#include "Stack.h"

using namespace std;

int masin()
{
	Stack <char> stack;

	char x = '0';

	do
	{
		cin >> x;
		stack.push(x);

	} while (x != '0');

	while (!stack.empty())
	{
		cout << stack.pop() << endl;
	}

	system("pause");
	return 0;
}