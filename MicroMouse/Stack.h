#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
template <typename TData>
class Stack {
private:
    TData* elements;
    int _maxArraySize; // Max size off array; can resize.
    int _size; // Number of elements currently in the array.
    void resizeArray();
public:
    Stack<TData>() : _size(0), _maxArraySize(16) { // Constructor
        elements = new TData[_maxArraySize]; // Initial size of 16.
        /*for (int i = 0; i < _maxArraySize; i++) {
            elements[i] = NULL;
        }*/
    }
    ~Stack<TData>() { // Destructor
        delete[] elements;
    }
    void push(const TData&);
    const TData& pop();
    const TData& peek();
    int size();
    bool empty();
};

template <typename TData>
void Stack<TData>::push(const TData& data) {
    if (_size == _maxArraySize) {
        resizeArray(); // Resize internal array to double its current size.
    }
    elements[_size++] = data;
}

template <typename TData>
const TData& Stack<TData>::pop() { // Need to delete returned value if needed!
    TData data = elements[_size - 1];
    //elements[--_size] = NULL; // Set to null and decrement.
    _size--;
    return data;
}

template <typename TData>
const TData& Stack<TData>::peek() {
    return elements[_size - 1];
}

template <typename TData>
int Stack<TData>::size() {
    return _size;
}

template <typename TData>
bool Stack<TData>::empty() {
    return size == 0;
}

template <typename TData>
void Stack<TData>::resizeArray() {
    TData* oldData = elements;
    int oldSize = _maxArraySize;

    _maxArraySize *= 2; // Double the size.
    elements = new TData[_maxArraySize];

    for (int i = 0; i < oldSize; i++) { // Restore the data.
        elements[i] = oldData[i];
    }

    delete[] oldData; // Remove the old data.
}

#endif