#include <iostream>
#include "myvector.h"

using namespace std;

Vector::Vector()
{
    size = 0;
    capacity = 4;
}

void Vector::push_back(const Payload& x)
{
    if (size < capacity)
    {
        arr[size] = x;
        size = size + 1;
    }

    else
    {
        cout << "Error: Maximum capacity of the array has been reached" << endl;
    }
}

void Vector::pop_back()
{
    if (size == 0)
    {
        cout << "Error: Vector is already empty!" << endl;
    }

    else
    {
        arr[size - 1] = Payload();
        size = size - 1;
    }
}

int Vector::get_size() const
{
    return size;
}

int Vector::get_capacity() const
{
    return capacity;
}

/*
void Vector::showVector()
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].print() << ", ";
    }
    cout << "]" << endl;
}
*/