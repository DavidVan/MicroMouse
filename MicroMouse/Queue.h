#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

template <typename TData>

class Queue
{
private:
	TData * elements;
	int _maxArraySize;
	int mCount;

	int mHead;
	int mTail;

	void resize();

public:
	Queue <TData>();

	~Queue<TData>();

	void enqueue(const TData&);
	const TData& dequeue();
	const TData& peek();
	int getSize();
	bool isEmpty();
};

template <typename TData>

Queue <TData>::Queue()
{
	mHead = 0;
	mTail = 0;

	mCount = 0;
	_maxArraySize = 16;

	elements = new TData[_maxArraySize];

}

template <typename TData>

Queue <TData>::~Queue()
{
	delete[] elements;
}

template <typename TData>
void Queue<TData>::enqueue(const TData & data)
{
	if (mCount == _maxArraySize)
	{
		resize();
	}

	elements[mTail] = data;
	mCount++;
	mTail = (mTail + 1) % _maxArraySize;
}

template <typename TData>
const TData& Queue<TData>::dequeue()
{
	if (mCount == 0)
	{
		throw "Queue is Empty!";
	}

	mCount--;

	TData element = elements[mHead];
	mHead = (mHead + 1) % _maxArraySize;
	return element;
}

template <typename TData>
const TData & Queue<TData>::peek()
{
	return elements[mHead];
}

template <typename TData>
int Queue<TData>::getSize()
{
	return mCount;
}

template <typename TData>
bool Queue<TData>::isEmpty()
{
	return mCount == 0;
}

template <typename TData>
void Queue<TData>::resize()
{
	TData * oldData = elements;
	int oldSize = _maxArraySize;
	_maxArraySize *= 2;

	elements = new TData[_maxArraySize];

	int index = 0;

	do
	{
		elements[index] = oldData[mHead];
		mHead = (mHead + 1) % oldSize;
		index++;
	} while (mHead != mTail);

	mHead = 0;
	mTail = index;

	delete[] oldData;
}

#endif