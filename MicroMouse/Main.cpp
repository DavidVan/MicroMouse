#include "Queue.h"

using namespace std;

int main()
{
	Queue <char> queue;

	char x = '0';

	do
	{
		cin >> x;
		queue.enqueue(x);

	} while (x != '0');

	while (!queue.isEmpty())
	{
		cout << queue.dequeue() << endl;
	}

	system("pause");
	return 0;
}